#ifndef _TASK2_H_
#define _TASK2_H_

void task2(){
    enum class Task1States
    {
        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA; 
        break;
    }

    case Task1States::WAIT_DATA:
    {
        // evento 1:
        // Ha llegado al menos un dato por el puerto serial?
        if (Serial.available() > 0)
        {
            // DEBES leer ese dato, sino se acumula y el buffer de recepción
            // del serial se llenará.
            Serial.read();
            uint32_t var = 0;
            // Almacena en pvar la dirección de var.
            uint32_t *pvar = &var;
            // Envía por el serial el contenido de var usando
            // el apuntador pvar.
            printf("var content: %d\n", *pvar);
            // ESCRIBE el valor de var usando pvar
            *pvar = 10;
            printf("var content: %d\n", *pvar);
        }
        break;}

    default:
    {
        break;
    }
}
//boton 1
#endif