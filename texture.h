#include <SOIL/SOIL.h>

GLuint carregaTextura(const char* arquivo) {
    GLuint idTextura = SOIL_load_OGL_texture(arquivo,SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

    if (idTextura == 0) { // Caso a textura seja inalcançável
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }

    return idTextura;
}

GLuint texturaSol;

GLuint texturaMerc;
GLuint texturaVenus;
GLuint texturaTerra;
GLuint texturaMarte;
GLuint texturaLua;
GLuint texturaJupiter;
GLuint texturaUrano;
GLuint texturaNet;
GLuint texturaSat;
GLuint texturaFobos;
GLuint texturaDeimos;
GLuint texturaEuropa;
GLuint texturaGanimedes;
GLuint texturaCallisto;
