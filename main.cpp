//#ingure -clude <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>

using namespace std;
int frames = 0, plataforma, cont; 
GLfloat posX_obstaculos[8], posX, posY; // variaveis obstaculos
GLfloat tempo_novo, tempo_antigo, variacao_de_tempo; // variaveis controle de frames
GLfloat escalaX = 0, escalaY = 0; // variaveis "camera"
GLfloat tempo_pulo, tempo_inicial, t; // variaveis pulo
GLfloat posX_jogador = 0, posY_jogador = 4; // variaveis jogador
bool primeiro_desenho = true, rodando = true, pulando = false;

bool posicaoValida(GLfloat posicao)
{
    
    if(posicao>960 && posicao<=1000) return false; // estar logo antes da subida de plataforma
    if(posicao>1088) return false; // estar depois da linha de chegada
    if(posicao<50) return false; // estar muito no inicio
    if(posicao>1000 && posicao<1050) return false; // estar muito no inicio da plataforma nivel 1
    for(int i = 0; i< cont; i++) // estar muito próximo de algum dos outros
    {
        if(posicao>(posX_obstaculos[i]-50) && posicao<(posX_obstaculos[i]+50)) return false;
    }
    return true;
}

void geraPosicaoObstaculo()
{
    plataforma = rand() % 2;
    if(!plataforma)
    {
        posX = (rand() % 100)*10;
        posY = 4;
    }
    else
    {
        posX = ((rand() % 10)+100)*10;
        posY = 19;
    }
}

void criaObstaculo()
{
    cont = 0;
    int obs_1 = 0, obs_2 = 0, obs_3 = 0;
    if(primeiro_desenho)
    {
        primeiro_desenho = false;
        while(obs_1<2)
        {
            geraPosicaoObstaculo();
            while(!posicaoValida(posX)) 
            {
                geraPosicaoObstaculo();
            }  
            glBegin(GL_TRIANGLES);
                glVertex2f(posX, posY);
                glVertex2f(posX+10, posY);
                glVertex2f(posX+5, posY+10);
            glEnd(); 
            posX_obstaculos[cont] = posX;
            cont++;
            obs_1++;        
        }
        while(obs_2<3)
        {
            geraPosicaoObstaculo();
            while(!posicaoValida(posX)) 
            {
                geraPosicaoObstaculo();
            }  
            glBegin(GL_TRIANGLES);
                glVertex2f(posX, posY);
                glVertex2f(posX+10, posY);
                glVertex2f(posX+5, posY+10);
            glEnd(); 
            glBegin(GL_TRIANGLES);
                glVertex2f(posX+10, posY);
                glVertex2f(posX+20, posY);
                glVertex2f(posX+15, posY+10);
            glEnd(); 
            posX_obstaculos[cont] = posX;
            cont++;
            obs_2++;        
        }
        while(obs_3<3)
        {
            geraPosicaoObstaculo();
            while(!posicaoValida(posX)) 
            {
                geraPosicaoObstaculo();
            }  
            glBegin(GL_TRIANGLES);
                glVertex2f(posX, posY);
                glVertex2f(posX+10, posY);
                glVertex2f(posX+5, posY+10);
            glEnd(); 
            glBegin(GL_TRIANGLES);
                glVertex2f(posX, posY+10);
                glVertex2f(posX+10, posY+10);
                glVertex2f(posX+5, posY+20);
            glEnd(); 
            posX_obstaculos[cont] = posX;
            cont++;
            obs_3++;        
        }
    }
    else
    {
        //cout << "Segundo \n";
        while(cont<2)
        {
            if(posX_obstaculos[cont]>1000)
            {
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 19);
                    glVertex2f(posX_obstaculos[cont]+10, 19);
                    glVertex2f(posX_obstaculos[cont]+5, 29);
                glEnd(); 
            } 
            else
            {
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 4);
                    glVertex2f(posX_obstaculos[cont]+10, 4);
                    glVertex2f(posX_obstaculos[cont]+5, 14);
                glEnd(); 
            } 
            cont++;  
        }
        while(cont<5)
        {
            if(posX_obstaculos[cont]>1000)
            {
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 19);
                    glVertex2f(posX_obstaculos[cont]+10, 19);
                    glVertex2f(posX_obstaculos[cont]+5, 29);
                glEnd(); 
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont]+10, 19);
                    glVertex2f(posX_obstaculos[cont]+20, 19);
                    glVertex2f(posX_obstaculos[cont]+15, 29);
                glEnd(); 
            } 
            else
            {
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 4);
                    glVertex2f(posX_obstaculos[cont]+10, 4);
                    glVertex2f(posX_obstaculos[cont]+5, 14);
                glEnd(); 
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont]+10, 4);
                    glVertex2f(posX_obstaculos[cont]+20, 4);
                    glVertex2f(posX_obstaculos[cont]+15, 14);
                glEnd(); 
            } 
            cont++;  
        }
        while(cont<8)
        {
            if(posX_obstaculos[cont]>1000)
            {
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 19);
                    glVertex2f(posX_obstaculos[cont]+10, 19);
                    glVertex2f(posX_obstaculos[cont]+5, 29);
                glEnd(); 
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 29);
                    glVertex2f(posX_obstaculos[cont]+10, 29);
                    glVertex2f(posX_obstaculos[cont]+5, 39);
                glEnd();
            } 
            else
            {
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 4);
                    glVertex2f(posX_obstaculos[cont]+10, 4);
                    glVertex2f(posX_obstaculos[cont]+5, 14);
                glEnd(); 
                glBegin(GL_TRIANGLES);
                    glVertex2f(posX_obstaculos[cont], 14);
                    glVertex2f(posX_obstaculos[cont]+10, 14);
                    glVertex2f(posX_obstaculos[cont]+5, 24);
                glEnd();
            } 
            cont++;  
        }
    }
    
    
}

void criaPlataforma()
{
    glColor3f (0.30, 0.79, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(1000, 0);
        glVertex2f(1000, 4);
        glVertex2f(0, 4);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(1000, 0);
        glVertex2f(1004, 0);
        glVertex2f(1004, 15);
        glVertex2f(1000, 15);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(1000, 15);
        glVertex2f(1100, 15);
        glVertex2f(1100, 19);
        glVertex2f(1000, 19);
    glEnd(); 
    glColor3f (1.0,0.45,1.0);
    glBegin(GL_POLYGON);
        glVertex2f(1088, 19);
        glVertex2f(1090, 19);
        glVertex2f(1090, 49);
        glVertex2f(1088, 49);
    glEnd(); 

}

void criaJogador()
{
    glColor3f (0.5, 0.0, 0.5);
    glBegin(GL_POLYGON);
        glVertex2f(posX_jogador, posY_jogador);
        glVertex2f(posX_jogador+10, posY_jogador);
        glVertex2f(posX_jogador+10, posY_jogador+5);
        glVertex2f(posX_jogador, posY_jogador+5);
    glEnd();
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(posX_jogador, posY_jogador+5);
        glVertex2f(posX_jogador+10, posY_jogador+5);
        glVertex2f(posX_jogador+10, posY_jogador+10);
        glVertex2f(posX_jogador, posY_jogador+10);
    glEnd();
}

void puloJogador()
{ 
    tempo_pulo = glutGet(GLUT_ELAPSED_TIME)/1000.0; 
    t = tempo_pulo - tempo_inicial;
    if(t<(2.0*(24.0/9.8)))
    {
        posY_jogador = 4.0 + (24.0*t) - ((0.5)*(9.8)*(t*t));
        tempo_pulo = glutGet(GLUT_ELAPSED_TIME)/1000.0; 
        t = tempo_pulo - tempo_inicial;
    }
}

bool colisao_obstaculo()
{
    int i=0;
    if(posX_jogador>=1000 && posY_jogador<=15) return true;
    while(i<2)
    {
        if(posX_jogador>=posX_obstaculos[i] && posX_jogador<=posX_obstaculos[i]+10 && (posY_jogador<=10))
        {
            return true;
        }
        i++;
    }
    while(i<5)
    {
        if(posX_jogador>=posX_obstaculos[i] && posX_jogador<=posX_obstaculos[i]+20 && posY_jogador<=10)
        {
            return true;
        }
        i++;
    }
    while(i<8)
    {
        if(posX_jogador>=posX_obstaculos[i] && posX_jogador<=posX_obstaculos[i]+10 && posY_jogador<=20)
        {
            return true;
        }
        i++;
    }
    return false;
}

bool chegou()
{
    if(posX_jogador>=1088) return true;
    return false;
}

void handleKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 32:
            tempo_inicial = glutGet(GLUT_ELAPSED_TIME)/1000.0; 
            pulando = true;
        break;
	}
}

void display(void)
{
    if(rodando)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-100 + escalaX, 100 + escalaX, -20 + escalaY, 70 + escalaY);
        glClear (GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        criaPlataforma();
        criaObstaculo();
        criaJogador();
        escalaX += 0.01;
        if(pulando) puloJogador();
        posX_jogador += 0.01;
        /*if(colisao_obstaculo())
        {
            cout << "colidiu" << endl;
        }
        if(chegou())
        {
            cout << "chegou" << endl;
        }*/
        glutSwapBuffers();  
        glutPostRedisplay();
    }
}

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void novoMainLoop(){
    tempo_novo = glutGet(GLUT_ELAPSED_TIME);
    tempo_antigo = tempo_novo;
    while(rodando)
    {
        tempo_novo = glutGet(GLUT_ELAPSED_TIME);
        variacao_de_tempo = tempo_novo - tempo_antigo;
        if(frames==0 || variacao_de_tempo>(1/frames)) 
        {
            tempo_antigo = tempo_novo;
            glutMainLoopEvent(); 
        }
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize (1000, 500);
    glutInitWindowPosition (300, 10);
    glutCreateWindow ("Trabalho 2");
    init ();
    glutKeyboardFunc(handleKeyboard);
    //glutMouseFunc(handle_mouse);
    glutDisplayFunc(display);
    novoMainLoop();
    return 0;   /* ISO C requires main to return int. */
}

