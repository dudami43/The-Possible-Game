//#ingure -clude <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <ctime>

using namespace std;

char texto[50];
int frames = 0, plataforma, cont, marcado = -1; 
int estado = 0; // 0 Clique para iniciar 1 Você perdeu 2 Você ganhou 3 Jogo
GLfloat posX_obstaculos[8], posX, posY; // variaveis obstaculos
GLfloat tempo_novo, tempo_antigo, variacao_de_tempo; // variaveis controle de frames
GLfloat escalaX = 0, escalaY = 0; // variaveis "camera"
GLfloat tempo_pulo, tempo_inicial, t, rotacao = 0, altura = 4; // variaveis pulo
GLfloat posX_jogador = 0, posY_jogador = 4, tamanho = 10; // variaveis jogador
bool primeiro_desenho = true, pulando = false;

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
        glVertex2f(posX_jogador+tamanho, posY_jogador);
        glVertex2f(posX_jogador+tamanho, posY_jogador+(tamanho/2));
        glVertex2f(posX_jogador, posY_jogador+(tamanho/2));
    glEnd();
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(posX_jogador, posY_jogador+(tamanho/2));
        glVertex2f(posX_jogador+tamanho, posY_jogador+(tamanho/2));
        glVertex2f(posX_jogador+tamanho, posY_jogador+tamanho);
        glVertex2f(posX_jogador, posY_jogador+tamanho);
    glEnd();
}

void puloJogador()
{ 
    if(t<(2.0*(25.0/9.8)))
    {
        posY_jogador = altura + (25.0*t) - ((0.5)*(9.8)*(t*t));
        //rotacao -= 0.03;
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

void desenhaTexto()
{
    char iniciar[50];

	glColor3d(1, 1, 1);

    sprintf(iniciar, "INICIAR");
    glPushMatrix();
	    glRasterPos2f(235, 270);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    sprintf(iniciar, "00");
    glPushMatrix();
	    glRasterPos2f(130, 400);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    sprintf(iniciar, "30");
    glPushMatrix();
	    glRasterPos2f(240, 400);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    sprintf(iniciar, "60");
    glPushMatrix();
	    glRasterPos2f(350, 400);
        for (char *i = iniciar; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

    glPushMatrix();
	    glRasterPos2f(220, 130);
        for (char *i = texto; *i != 0; i++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
	glPopMatrix();

	//glFlush();
}

void menu()
{
    if(marcado == 00) glColor3f (1.0,0.45,1.0);
    else glColor3f (0.30, 0.79, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(100, 450);
        glVertex2f(180, 450);
        glVertex2f(180, 380);
        glVertex2f(100, 380);
    glEnd();  

    if(marcado == 30) glColor3f (1.0,0.45,1.0);
    else glColor3f (0.30, 0.79, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(210, 450);
        glVertex2f(290, 450);
        glVertex2f(290, 380);
        glVertex2f(210, 380);
    glEnd();  

    if(marcado == 60) glColor3f (1.0,0.45,1.0);
    else glColor3f (0.30, 0.79, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(320, 450);
        glVertex2f(400, 450);
        glVertex2f(400, 380);
        glVertex2f(320, 380);
    glEnd();
    
    glColor3f (0.30, 0.79, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(100, 350);
        glVertex2f(400, 350);
        glVertex2f(400, 200);
        glVertex2f(100, 200);
    glEnd();   
    glBegin(GL_POLYGON);
        glVertex2f(100, 170);
        glVertex2f(400, 170);
        glVertex2f(400, 110);
        glVertex2f(100, 110);
    glEnd();   
    desenhaTexto();
}

void handleKeyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 32:
            cout << "X " << posX_jogador << " Y " << posY_jogador << endl;
            if((posX_jogador<=1000 && posY_jogador>=4 && posY_jogador<=4.1) || (posX_jogador>1000 && posY_jogador>=19 && posY_jogador<=19.1))
            {
                tempo_inicial = glutGet(GLUT_ELAPSED_TIME)/1000.0; 
            }
            tempo_pulo = glutGet(GLUT_ELAPSED_TIME)/1000.0; 
            t = tempo_pulo - tempo_inicial;
            pulando = true;
        break;
	}
}

void handleMouse(int button, int state, int x, int y)
{
    y = 500 - y;
    x = x/2;    
    cout << " X " << x << " Y " << y << endl;
    if(estado != 3 && estado != 4)
    {
        if(y>=380 && y<=450)
        {
            if(x>=100 && x<=180)
            {
                frames = marcado = 00;
            }
            if(x>=210 && x<=290)
            {
                frames = marcado = 30; 
            }
            if(x>=320 && x<=400)
            {
                frames = marcado = 60;     
            }
        }
        if(y>=200 && y<=350 && x>=100 && x<=400 && marcado!= -1)
        {
            estado = 3; escalaX = 0; escalaY = 0;
            posX_jogador = 0; posY_jogador = 4;
            rotacao = 0; altura = 4; tamanho = 10;
        } 
    }
}

void display(void)
{
    if(estado==3)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-100 + escalaX, 100 + escalaX, -20 + escalaY, 70 + escalaY);
        glClear (GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        criaPlataforma();
        criaObstaculo();
        glPushMatrix();
            glTranslatef(posX_jogador,posY_jogador,0);
            glRotatef(rotacao,0.0,0.0,1.0);
            glTranslatef(-posX_jogador,-posY_jogador,0);
            criaJogador();
        glPopMatrix();
        escalaX += 0.01;
        if(pulando) puloJogador();
        posX_jogador += 0.01;
        if(posX_jogador>=1000) altura = 19;
        if(colisao_obstaculo())
        {
            cout << "colidiu" << endl;
            estado = 4;
        }
        if(chegou())
        {
            cout << "chegou" << endl;
            estado = 2;
        }
    }
    else if(estado == 0)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 500, 0, 500);
        glClear (GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        menu();
        sprintf(texto, "Clique em iniciar");
    }
    else if(estado == 1)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 500, 0, 500);
        glClear (GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        menu();
        sprintf(texto, "Voce perdeu");
    }
    else if(estado == 2)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0, 500, 0, 500);
        glClear (GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        menu();
        sprintf(texto, "Voce ganhou");
    }
    else if(estado == 4)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-100 + escalaX, 100 + escalaX, -20 + escalaY, 70 + escalaY);
        glClear (GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        criaPlataforma();
        criaObstaculo();
        glPushMatrix();
            glTranslatef(posX_jogador,posY_jogador,0);
            glRotatef(rotacao,0.0,0.0,1.0);
            glTranslatef(-posX_jogador,-posY_jogador,0);
            criaJogador();
        glPopMatrix();
        tamanho-=0.01;
        if(int(tamanho) == 0) estado = 1;
    }
    glutSwapBuffers();  
    glutPostRedisplay();
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
    while(true)
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
    glutMouseFunc(handleMouse);
    glutDisplayFunc(display);
    novoMainLoop();
    return 0;   /* ISO C requires main to return int. */
}

