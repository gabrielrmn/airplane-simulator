/*Para carregar arquivos .obj usamos DisplayList! Primeiro devemos ler o obj junto a seu .mtl e depois criar um numero para a lista.
para desenha-los, basta chamar a lista com glCallList() !*/
#include "biblioteca.h"
#include "musica.h"
#include "glm.h"
#include "glmint.h"

#define MAX(x,y) (((x) > (y)) ? (x) : (y))

//Declara
GLMmodel* pmodel = NULL;
GLMmodel* cmodel = NULL;
GLMmodel* cubemodel = NULL;
GLMmodel* placamodel = NULL;
GLMmodel* helicemodel = NULL;
GLMmodel* millmodel = NULL;
GLMmodel* rotatemodel = NULL;
GLMmodel* heliportmodel = NULL;
GLMmodel* painelmodel = NULL;
<<<<<<< HEAD
=======
GLMmodel* birdmodel = NULL;
>>>>>>> Computer Graphics

GLuint cidade; //numero da lista a ser desenhada
GLuint personagem;
GLuint cube1;
GLuint placa;
GLuint helice;
GLuint mill;
GLuint rotate;
GLuint heliport;
GLuint painel;
<<<<<<< HEAD
=======
GLuint bird;
>>>>>>> Computer Graphics

float d = 1.0;           // Intensidade da cor difusa da luz branca
float e = 1.0;           // Intensidade da cor especular da luz branca

float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0,angle2=0,ypouso=-40; // -40 --> posicao y inicial do aviao
<<<<<<< HEAD
=======
float angle3=0;
>>>>>>> Computer Graphics

float cRadius = 10.0f; // raio de distancia do personagem

float lastx, lasty;

float fps;
int momentoAnterior;

int camera = 0;
int controllCam1 = 0;
int controllCam3 = 0;
int loading = 1;
int light0Ligada = 0;
int fogLigado = 0;
int pousarOn = 0;
int limitePouso1x = -69;
int limitPouso2x = -81;
int limitPouso1z = 79;
int limitPouso2z = 97;

void init (void) {
    glClearColor(1, 1, 1, 1);
    readModels();
    createDisplayList();
}

//Função que desenha obj;
void readModels(){
	pmodel = glmReadOBJ("pasta/FREOBJ.obj");
	cmodel = glmReadOBJ("pasta/castleostorozac.obj");
	cubemodel = glmReadOBJ("pasta/cube1.obj");
	placamodel = glmReadOBJ("pasta/LasVegasSign.obj");
	helicemodel = glmReadOBJ("pasta/propeller.obj");
    millmodel = glmReadOBJ("pasta/casa.obj");
    rotatemodel = glmReadOBJ("pasta/helice2.obj");
    heliportmodel = glmReadOBJ("pasta/untitled.obj");
    painelmodel = glmReadOBJ("pasta/HoloPannelv2.obj");
<<<<<<< HEAD
=======
    birdmodel = glmReadOBJ("pasta/hummingbird.obj");
>>>>>>> Computer Graphics
}

void createDisplayList(){
	cidade = glmList(cmodel,GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH );
	personagem = glmList(pmodel,GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH );
	cube1 = glmList(cubemodel,GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH );
	placa = glmList(placamodel,GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH );
	helice = glmList(helicemodel, GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH);
    mill = glmList(millmodel, GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH);
    rotate = glmList(rotatemodel, GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH);
    heliport = glmList(heliportmodel, GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH);
    painel = glmList(painelmodel, GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH);
<<<<<<< HEAD
=======
    bird = glmList(birdmodel, GLM_COLOR | GLM_TEXTURE | GLM_SMOOTH);
>>>>>>> Computer Graphics
}

void enable (void) {

    if(light0Ligada){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
    if(fogLigado){
        glEnable(GL_FOG);
    }

    //Propriedades da luz ambiente,difusa e especular
    float lightAmb[] = { 1.0, 1.0, 1.0, 1.0 };
    float lightDif0[] = { d, d, d, 1.0 };
    float lightSpec0[] = { e, e, e, 1.0 };

    //Definindo as luzes
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);

    //Habilita o teste de profundidade
    glEnable(GL_DEPTH_TEST);

<<<<<<< HEAD
    float cor[] = { 0.4, 0.75, 0.4};
=======
    float cor[] = { 0.4, 0.4, 0.75};
>>>>>>> Computer Graphics
    glClearColor(cor[0], cor[1], cor[2], 1);

    glFogi(GL_FOG_MODE, GL_EXP2);        // exp²
    glFogfv(GL_FOG_COLOR, cor);         // Cor
    glFogf(GL_FOG_DENSITY, 0.015);      // Densidade
<<<<<<< HEAD
    glHint(GL_FOG_HINT, GL_DONT_CARE);  
    glFogf(GL_FOG_START,10);            // inicial
    glFogf(GL_FOG_END, 10);           // final                   
=======
    glHint(GL_FOG_HINT, GL_NICEST);  
    glFogf(GL_FOG_START,100);            // inicial
    glFogf(GL_FOG_END, 150);           // final                   
>>>>>>> Computer Graphics

    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    if(!light0Ligada){
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
    }
    if(!fogLigado){
        glDisable(GL_FOG);
    }
}

void gerenciaCamera(){
    if(camera == 1){
        gluLookAt(0 , 50 , 0 , 0 , 0 , 0 , 0 , 0 ,-1);
        if(controllCam1==0){
            angle = 0;
            xrot = 0, yrot = 0;
            controllCam1++;
        }
    }

    if(camera == 3)
        glTranslatef(0.0f, -0.35f, 0.6f); //translada a visao para dentro do aviao (1st person camera)
}

void desenhaPlano(){ // desenha o chao do mundo
	glPushMatrix();
    glBegin(GL_POLYGON);
    	glColor3f(0, .5, 0);
<<<<<<< HEAD
       	glVertex3f(-10000,-25,-10000);
       	glVertex3f(-10000,-25,10000);
       	glVertex3f(10000,-25,10000);
       	glVertex3f(10000,-25,-10000);
=======
       	glVertex3f(-10000,-50,-10000);
       	glVertex3f(-10000,-50,10000);
       	glVertex3f(10000,-50,10000);
       	glVertex3f(10000,-50,-10000);
>>>>>>> Computer Graphics
    glEnd();
    glPopMatrix();
}

void verificaPouso(){

    if(ypouso< -5 && pousarOn) //altura definida para a pista de pouso
        ypouso+=0.1;

    if(ypouso > -40 && !pousarOn) //altura definida para a pista de pouso
        ypouso-=0.1;
}

void atualizaFps(){

	int momentoAtual = glutGet(GLUT_ELAPSED_TIME);
	int delta = momentoAtual - momentoAnterior;
	fps = 1000.0f / MAX(delta,1.0f);

	momentoAnterior = momentoAtual;

	//Reescreve fps no titulo

	char tituloDaJanela[200];
	sprintf(tituloDaJanela,
			"Beta (%2.f fps)",
			fps);
	glutSetWindowTitle(tituloDaJanela);
}

void display (void){
	atualizaFps();
    glClearColor (0.0,0.0,0.0,1.0); //limpa a tela
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    enable();

    glLoadIdentity(); 

    if(camera == 1 || camera == 3){
    	gerenciaCamera();
    }
    else{
        glTranslatef(0.0f, 0.0f, -cRadius); //translada a visao para tras do personagem
        glRotatef(xrot,1.0,0.0,0.0); //rotaciona a visao do personagem e do cenario 
    }

    glPushMatrix();
        glRotatef(90,1,0,0);// para colocar o aviao na posicao desejada
        glRotatef(180,0,1,0);// para colocar o aviao na posicao desejada
        glScalef(1,1,1);
        glCallList(personagem);
    glPopMatrix();

    glPushMatrix();
    	glTranslated(-0.025,0,-1.2);
    	glRotatef(-30,1,0,0);
    	glScalef(.075,.05,.05);
    	glCallList(painel);
    glPopMatrix();


    glPushMatrix();
        glTranslated(0,-0.015,-1.9); //colocando a helice na frente do aviao
        glRotatef(90,1,0,0); //para colocar a helice na posicao desejada
        if(pousarOn == 0)
        	glRotatef(angle,0,1,0); //gira a helice do aviao (ideia de movimento)
        glScalef(.004,.004,.004);
        glCallList(helice);
    glPopMatrix();
    
    if(camera!=1) //a camera 1 desabilita a visao pelo mouse!
        glRotatef(yrot,0.0,1.0,0.0);  //rotaciona a camera
    
	glTranslated(-xpos,ypouso,-zpos); //translada a tela para a posicao da camera

    glPushMatrix();
        glTranslated(xpos,0.0f,zpos); //para o skybox andar junto com o personagem
        glScalef(150,150,150);
        glCallList(cube1);
    glPopMatrix();

    desenhaPlano();

    glPushMatrix();
        glTranslated(0,0,0);
        glScalef(1,1,1);
        glCallList(cidade);
    glPopMatrix();

    glPushMatrix();
        glTranslated(18,85,100);
        glScalef(1,1,1);
        glCallList(mill);
    glPopMatrix();

    glPushMatrix();
        glTranslated(18,95.8,100);
        glRotatef(angle2,0,0,1); //gira o moinho
        glTranslated(0,-10.8,0);
        glScalef(1,1,1);
        glCallList(rotate);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-15,-70);
        glScalef(.1,.1,.1);
        glCallList(placa);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-74,5,90);
        glRotatef(90,0,1,0);
        glScalef(15,1,15);
        glCallList(heliport);
    glPopMatrix();

<<<<<<< HEAD
=======
    glPushMatrix();
        glTranslated(0,50,0);
        glRotatef(angle3,0,1,0);
        glTranslated(50,0,0);
        glScalef(.01,.01,.01);
        glCallList(bird);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,75,0);
        //glRotatef(90,0,1,0);
        glRotatef(-angle3,0,1,0);
        glTranslated(50,0,0);
        glScalef(-.01,.01,-.01);
        glCallList(bird);
    glPopMatrix();

>>>>>>> Computer Graphics
    verificaPouso();

    angle+=18; //incrementa o angulo para controlar a velocidade de rotacao da helice!
    angle2+=9; // incrementa o angulo para controlar a velocidade de rotacao do moinho!
<<<<<<< HEAD
=======
    angle3-=0.3; // incrementa o angulo para controlar a velocidade de rotacao do bird!
>>>>>>> Computer Graphics

    glutSwapBuffers(); //swap buffers
}
 
void reshape (int w, int h) {

    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //define o viewport
    glMatrixMode (GL_PROJECTION); //define a matrix to projection
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0); //define a perspectiva  (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //define a matrix back to model
}

void keyboard (unsigned char key, int x, int y) { // teclado e funcionalidades

    if(key == '1'){
        camera = 1;
        controllCam3 = 0;
    }

    if(key == '3'){
        camera = 3;
        controllCam1 = 0;
    }

    if(key == '2'){
        camera = 2;
        controllCam1 = 0;
        controllCam3 = 0;
    }

    if (key=='w' && pousarOn == 0){
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f); 
        xpos += (sin(yrotrad)) * 0.5;
        zpos -= (cos(yrotrad)) * 0.5;
        ypos -= (sin(xrotrad)) * 0.5;
    }

    if (key== 's' && pousarOn == 0){
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f); 
        xpos -= (sin(yrotrad)) * 0.5;
        zpos += (cos(yrotrad)) * 0.5;
        ypos += (sin(xrotrad)) * 0.5;
    }

    if (key== 'd' && pousarOn == 0){
        float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xpos += (cos(yrotrad)) * 0.5;
        zpos += (sin(yrotrad)) * 0.5;
    }

    if (key== 'a' && pousarOn == 0){
        float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xpos -= (cos(yrotrad)) * 0.5;
        zpos -= (sin(yrotrad)) * 0.5;
    }

    if (key== 'l')
        light0Ligada = !light0Ligada;
    
    if(key== 'n')
        fogLigado = !fogLigado;
    
    if(key=='p' && xpos > limitPouso2x && xpos < limitePouso1x && zpos > limitPouso1z && zpos < limitPouso2z) //o pouso ou subida do aviao so ocorrera se ele estiver na area correta!
        pousarOn = !pousarOn;

    if (key==27)
        exit(0);
}

void mouseMovement(int x, int y) {  // funcao que gerencia o mouse
    if(camera != 1){
        int diffx=x-lastx; //checa a diferenca entre as posicoes
        int diffy=y-lasty; //checa a diferenca entre as posicoes
        lastx=x; //define lastx para a atual posicao de x 
        lasty=y; //define lasty para a atual posicao de y
        xrot += (float) diffy; //define xrot para xrot com a adicao
        if(xrot>90 || xrot<-90)
            xrot-=diffy;
        yrot += (float) diffx;    //define o xrot para yrot com a adicao
    }
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitContextVersion(1, 1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); 
    glutInitWindowSize (500, 500); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("BETA");
    glutEnterGameMode();
    init (); 
    tocarMusica("pasta/countryroads.mp3",-1);
    glutSetCursor(GLUT_CURSOR_NONE);
    glutDisplayFunc (display); 
    glutIdleFunc (display); 
    glutReshapeFunc (reshape);
    glutPassiveMotionFunc(mouseMovement); //check para o mouse
    glutKeyboardFunc (keyboard); 
    glutMainLoop ();
    return 0;
}
