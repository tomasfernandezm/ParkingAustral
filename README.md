# ParkingAustral

Proyecto para implementar un sistema de control de lugares en el estacionamiento de la Universidad Austral para la materia Organización de Computadoras

## HIPÓTESIS
- conocemos todos los caminos de entrada y salida posibles. Para el caso del estacionamiento de la Plaza, establecemos una entrada y una salida, que comparten el mismo camino.

- si la entrada y salida comparten camino entonces 2 autos no podrán pasar por el mismo camino a la vez.

## PROBLEMAS POSIBLES DEL CONCEPTO
- que haya un auto parado
- que pase un grupo de personas
- que pase una persona
- detecciones involuntarias

## FUNCIONAMIENTO GENERAL

- si el auto está entrando -> primero activar el primer sensor y después el segundo
- si el auto está saliendo -> primero activar el segundo sensor y después el primero.
- para ambos casos hay que tener en cuenta que no haya un doble conteo para el mismo auto

## SENSORES POSIBLES

- LASER CON FOTORECEPTOR
- BARRERA INFRAROJA
- SENSORES DE PRESIÓN
- SENSORES MAGNÉTICOS
- BARRERA CON BOTÓN

## PRUEBA DE ERRORES

- hay que tener un delta t para verificar si es un auto el que está cruzando. Con este delta t en realidad vamos a estar verificando la longitud del auto dado por la fórmula v x d = t.

- para verificar si un auto está parado, hay que tener un tiempo máximo de medición.

- para verificar si es un grupo de personas, poner el laser a nivel de las ruedas, para poder diferenciar entre la cantidad de patas y la cantidad de ruedas (que siempre van a hacer 2).

- como se puede doblar a distintas velocidades debemos tener un márgen de delta t.