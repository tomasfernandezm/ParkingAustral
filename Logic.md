# Lógica del Circuito

## Auto entrando

### Caso 1: Auto afuera del sistema
Tienen que estar todos los triggers apagados

### Caso 2: Auto entrando al estacionamiento que pasa por el primer sensor
Se activa el trigger de entrada. Arranca la medición del delta.

#### Caso 2.1: El auto vuelve para atrás y decide no entrar al sistema
Debido a que el auto no está tocando ningún sensor, todos los triggers tendrían que estar apagados. El delta setteado a 0.

#### Caso 2.2 El auto se queda parado en la entrada, activando el sensor.
El delta tendría que seguir corriendo, mismas características del Caso 2.

### Caso 3: Auto entrando al estacionamiento que pasa por el primer y el segundo sensor.
Todo sigue igual

### Caso 4: Auto entrando al estacionamiento que ya pasó por el primer sensor y está activando el segundo.
Todo sigue igual

### Caso 5: El auto entró al estacionamiento
Si el delta es mayor que el tiempo mínimo se suma uno al contador. El auto entró exitosamente.

## Salida
Misma lógica que a la entrada, pero al revés
