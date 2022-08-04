#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_opengl.h>

#include "texture.h"
#include "sol.h"
#include "mercurio.h"
#include "venus.h"
#include "terra.h"
#include "marte.h"
#include "jupiter.h"
#include "saturno.h"
#include "urano.h"
#include "netuno.h"
#include "lua.h"
#include "fobos.h"
#include "deimos.h"
#include "europa.h"
#include "callisto.h"
#include "ganimedes.h"

// Variáveis de controle
int controle = 1; // Habilita a luz
int orbita = 1; // Habilita a orbita

// Determina a distância da visão
float mX = 0; // Distância em X
float mY = 0; // Distância em Y
int dist = -30; // Manipulação do campo de visão

int w1=0; // Recebe a nova largura
int h1=0; // Recebe a nova altura

// Divisões das esferas
int slices = 27;
int stacks = 27;

// Cores da luz e a declaração do especMaterial
float r,g,b;
GLint especMaterial;

// Determina a posição/ vista
int orient = -70;

// Função callback chamada quando o tamanho da janela  alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    w1=w;
    h1=h;
    // Evita a divisao por zero
    if(h == 0) h = 1;

    GLfloat fAspect =(GLfloat) w/(GLfloat)h;

    // Especifica as dimenses da Viewport - melhor ficar no metodo desenha
    glViewport(0, 0, w,h);

    // Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa matriz de coordenadas de projeção
	glLoadIdentity();

    gluPerspective (16, fAspect, 1, 800);
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Maior qualidade nos gráficos
   	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void DefineIluminacao (void)
{
    GLfloat luzAmbiente[4]={0.4,0.4,0.4,1.0};
    GLfloat luzDifusa[4]={1.0,1.0,1.0,1.0};          // "cor"
    GLfloat luzEspecular[4]={10.0, 10.0, 10.0, 1.0}; // "brilho"
    GLfloat posicaoLuz[4]={0.0, 0.0, 0.0, 1.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={1.0,1.0,1.0,1.0};

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
}

void Desenha(void)
{
    int i;
    glDrawBuffer(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    DefineIluminacao(); // Inicia a iluminação

    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Determina a distância de quem observa
	glTranslated(mX, mY, dist);
	// Alterna as orientações
	glRotated(orient, 1, 0, 0);

	// SOL
	criaSol(slices,stacks,texturaSol);

	// Planetas
    criaMerc(slices,stacks,texturaMerc);
    criaVenus(slices,stacks,texturaVenus);
	criaTerra(slices,stacks,texturaTerra);
	criaMarte(slices,stacks,texturaMarte);
	criaJupiter(slices,stacks,texturaJupiter);
	criaSat(slices,stacks,texturaSat);
	criaNet(slices,stacks,texturaNet);
	criaUrano(slices,stacks,texturaUrano);
	criaLua(slices,stacks,texturaLua);
	criaFobos(slices,stacks,texturaFobos);
	criaDeimos(slices,stacks,texturaDeimos);
	criaEuropa(slices,stacks,texturaEuropa);
	criaCallisto(slices,stacks,texturaCallisto);
	criaGanimedes(slices,stacks,texturaGanimedes);

	if (orbita == 1){
         // Orbita de Mercúrio
        glColor3d(0.4,0.4,0.4);
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
                for (i = 0; i < 100 + 1; i++) {
                    glVertex2f( 4 * cos(2.0 * 3.14 * i / 100),4* sin(2.0 * 3.14 * i / 100) );
                }
            glEnd();
        glPopMatrix();

        // Orbita de Venus
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
                for (i = 0; i < 100; i++){
                    glVertex2f(5 * cos(2.0 * 3.14 * i / 100),5.0 * sin(2.0 * 3.14 * i / 100) );
                }
        glEnd();
        glPopMatrix();

        // Orbita da Terra
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
            for (i = 0; i < 100; i++) {
                glVertex2f(6.5 * cos(2.0 * 3.14 * i / 100),6.5* sin(2.0 * 3.14 * i / 100) );
            }
        glEnd();
        glPopMatrix();

        // Orbita da Marte
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
            for (i = 0; i < 100; i++) {
                glVertex2f(8 * cos(2.0 * 3.14 * i / 100),8* sin(2.0 * 3.14 * i / 100) );
            }
        glEnd();
        glPopMatrix();

        // Orbita da Júpiter
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
            for (i = 0; i < 100; i++) {
                glVertex2f(9.5 * cos(2.0 * 3.14 * i / 100),9.5* sin(2.0 * 3.14 * i / 100) );
            }
        glEnd();
        glPopMatrix();

        // Orbita da Saturno
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
            for (i = 0; i < 100; i++) {
                glVertex2f(10.5 * cos(2.0 * 3.14 * i / 100),10.5* sin(2.0 * 3.14 * i / 100) );
            }
        glEnd();
        glPopMatrix();

        // Orbita da Netuno
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
            for (i = 0; i < 100; i++) {
                glVertex2f(12 * cos(2.0 * 3.14 * i / 100),12* sin(2.0 * 3.14 * i / 100) );
            }
        glEnd();
        glPopMatrix();

        // Orbita da Urano
        glPushMatrix();
            glBegin(GL_LINE_LOOP);
            for (i = 0; i < 100; i++) {
                glVertex2f(13 * cos(2.0 * 3.14 * i / 100),13* sin(2.0 * 3.14 * i / 100) );
            }
        glEnd();
        glPopMatrix();
	}

    glutSwapBuffers();
}

void Inicializa (void)
{
    r = 1.0;
    g = 1.0;
    b = 1.0;
    especMaterial = 10;

	//carregar texturas
	texturaSol = carregaTextura("Texturas/sol.png");
	texturaTerra = carregaTextura("Texturas/Planetas/terra.png");
	texturaMerc = carregaTextura("Texturas/Planetas/mercurio.png");
	texturaVenus = carregaTextura("Texturas/Planetas/venus.png");
	texturaMarte = carregaTextura("Texturas/Planetas/marte.png");
	texturaJupiter = carregaTextura("Texturas/Planetas/jupiter.png");
	texturaSat = carregaTextura("Texturas/Planetas/saturno.png");
	texturaUrano = carregaTextura("Texturas/Planetas/urano.png");
	texturaNet = carregaTextura("Texturas/Planetas/netuno.png");
	texturaLua = carregaTextura("Texturas/Satelites/lua.png");
	texturaFobos = carregaTextura("Texturas/Satelites/fobos.jpg");
	texturaDeimos = carregaTextura("Texturas/Satelites/deimos.png");
	texturaEuropa = carregaTextura("Texturas/Satelites/europa.png");
	texturaCallisto = carregaTextura("Texturas/Satelites/callisto.png");
	texturaGanimedes = carregaTextura("Texturas/Satelites/ganimedes.png");

    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
	// Habilitar o uso de texturas
	//glEnable ( GL_TEXTURE_2D );
	glEnable(GL_COLOR_MATERIAL);
	//carregar texturas
	//carregar_texturas();
	//negocio para nao ficar mais transparente
	glEnable(GL_DEPTH_TEST);
	// Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

	// Define a cor de fundo da janela de visualizao como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//chama metodo para compilar os objetos e gerar a listas de exibicao
	//compilarObjetosDaCena();
}

void idle(void)
{
    glutPostRedisplay();
}

void teclas(unsigned char key, int x, int y){
    switch(key){
    case 27:
        exit(0);
        break;
    case 'c':
        if(orient == -70){
            orient = 0;
            dist = -80;
            mX = 0;
            mY = 0;
        }
        else{
            orient = -70;
            dist = -30;
            mX = 0;
            mY = 0;
        }
        break;
    case 'l':
        if (controle == 1){
            glDisable(GL_LIGHT0);
            controle = 0;
        }
        else{
            glEnable(GL_LIGHT0);
            controle = 1;
        }
        break;
    case 'o':
        if(orbita == 1) orbita = 0;
        else orbita = 1;
        break;
    }
}

void Rolamento ( int button, int state, int x, int y )
{

	if(button == 3)dist+=2;
	else if(button == 4)dist-=2;

    glutPostRedisplay();
}

void teclasEspeciais(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            mY -= 0.5;
            break;
        case GLUT_KEY_DOWN:
            mY += 0.5;
            break;
        case GLUT_KEY_LEFT:
            mX += 0.5;
            break;
        case GLUT_KEY_RIGHT:
            mX -= 0.5;
            break;
        }
   glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    // SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); //Inicia o áudio do SDL em todo projeto
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 ){
       printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    }
    //Abertura de áudio a partir do SDL, dessa forma, toda vez que o áudio for fechado, Mix_OpenAudio deve ser iniciado
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ){
       printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    // GLU
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH ); //GLUT_DEPTH: buffer para evitar transparencia(por profundidade)
    glutInitWindowSize(640,480); //tamanha inicial da janela
    glutInitWindowPosition(10,10); //posicao inicial
    glutCreateWindow("Sistema solar"); //nome da janela
    glutDisplayFunc(Desenha); //funcao onde fica todas as rotinas de desenho
    glutReshapeFunc(AlteraTamanhoJanela); //configura o tamanho da janela, camera e etc
    Inicializa(); //inicializa alguns parametros
    glutKeyboardFunc(teclas);
    glutMouseFunc(Rolamento);
    glutSpecialFunc(teclasEspeciais);
    glutIdleFunc(idle);

    // MIX
    Mix_Music *background = Mix_LoadMUS("interestelar.wav");
    Mix_PlayMusic(background, -1);

    //Finalizações da Main
    Mix_CloseAudio(); //Fecha o áudio
    glutMainLoop();
    SDL_Quit(); //Interrompe a instância iniciada pelo SDL_Init

    return 0;
}
