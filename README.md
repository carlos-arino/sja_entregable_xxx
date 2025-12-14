# Problema Microcontroladores: Invernadero Inteligente

## Instrucciones de Selección del Problema

Este problema tiene diferentes datos dependiendo del DNI del alumno. Se basa en el valor de las tres últimas cifras del DNI ($c, d, u$).

**Ejemplo:** DNI 20339950R -> **950**. En este caso $c=9, d=5, u=0$.

Se comprueba si las centenas, decenas y unidades son iguales o mayores que 5 para asignar el código binario del problema (0 o 1):

* Si **$c < 5$** -> El primer dígito es **0** (Control de Sombreado - Sensor Analógico).
* Si **$c \ge 5$** -> El primer dígito es **1** (Control de Ventilación - Sensor Digital).
* Si **$d < 5$** -> El segundo dígito es **0** (Motor Paso a Paso).
* Si **$d \ge 5$** -> El segundo dígito es **1** (Motor DC).
* Si **$u < 5$** -> El tercer dígito es **0** (Feedback por Encoder).
* Si **$u \ge 5$** -> El tercer dígito es **1** (Feedback por Potenciómetro).

En el ejemplo anterior (**950**): $c \ge 5$ (1), $d \ge 5$ (1), $u < 5$ (0). Se asignará el **Problema 110**.

La entrega se realiza en el aula virtual con el código del archivo de extensión `.ino`. Este debe incluir el enlace a la simulación realizada en Wokwi.

---

## Problema 000
Se quiere instrumentar el control de sombreado de un invernadero inteligente. Para ello se dispone de un sensor de luminosidad (LDR/Fotorresistencia) que entrega una señal analógica. El programa debe leer el valor analógico (ADC) y transformarlo a un porcentaje de luz de 0 a 100%.

Posteriormente, se debe desplegar el **toldo** de forma proporcional: 0% de luz implica toldo recogido (0º) y 100% de luz implica toldo totalmente extendido (90º).

Para lograr este movimiento, el eje del toldo tiene conectado un **motor paso a paso** de 200 pulsos por vuelta. Para verificar la posición, se dispone de un **encoder absoluto de 4 bits** codificado en código Gray solidario al eje.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/123/luz` con el valor de luminosidad actual en porcentaje.
* Topic: `sja003/invernadero/123/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[10, 45, 80, 90, 65]"`.

El número **123** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

---

## Problema 001
Se quiere instrumentar el control de sombreado de un invernadero inteligente. Para ello se dispone de un sensor de luminosidad (LDR/Fotorresistencia) que entrega una señal analógica. El programa debe leer el valor analógico (ADC) y transformarlo a un porcentaje de luz de 0 a 100%.

Posteriormente, se debe desplegar el **toldo** de forma proporcional: 0% de luz implica toldo recogido (0º) y 100% de luz implica toldo totalmente extendido (90º).

Para lograr este movimiento, el eje del toldo tiene conectado un **motor paso a paso** de 200 pulsos por vuelta. Para verificar la posición, se dispone de un **potenciómetro** conectado al eje que mide la posición real de la estructura para asegurar que es correcta.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/128/luz` con el valor de luminosidad actual en porcentaje.
* Topic: `sja003/invernadero/128/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[10, 45, 80, 90, 65]"`.

El número **128** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

---

## Problema 010
Se quiere instrumentar el control de sombreado de un invernadero inteligente. Para ello se dispone de un sensor de luminosidad (LDR/Fotorresistencia) que entrega una señal analógica. El programa debe leer el valor analógico (ADC) y transformarlo a un porcentaje de luz de 0 a 100%.

Posteriormente, se debe desplegar el **toldo** de forma proporcional: 0% de luz implica toldo recogido (0º) y 100% de luz implica toldo totalmente extendido (90º).

Para lograr este movimiento, se utiliza un **motor de corriente continua** con su driver, que se controla mediante una señal PWM; la velocidad es proporcional a dicha tensión. Para verificar la posición, se dispone de un **encoder absoluto de 4 bits** codificado en código Gray solidario al eje.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/182/luz` con el valor de luminosidad actual en porcentaje.
* Topic: `sja003/invernadero/182/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[10, 45, 80, 90, 65]"`.

El número **182** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

---

## Problema 011
Se quiere instrumentar el control de sombreado de un invernadero inteligente. Para ello se dispone de un sensor de luminosidad (LDR/Fotorresistencia) que entrega una señal analógica. El programa debe leer el valor analógico (ADC) y transformarlo a un porcentaje de luz de 0 a 100%.

Posteriormente, se debe desplegar el **toldo** de forma proporcional: 0% de luz implica toldo recogido (0º) y 100% de luz implica toldo totalmente extendido (90º).

Para lograr este movimiento, se utiliza un **motor de corriente continua** con su driver, que se controla mediante una señal PWM; la velocidad es proporcional a dicha tensión. Para verificar la posición, se dispone de un **potenciómetro** conectado al eje que mide la posición real de la estructura.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/189/luz` con el valor de luminosidad actual en porcentaje.
* Topic: `sja003/invernadero/189/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[10, 45, 80, 90, 65]"`.

El número **189** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

---

## Problema 100
Se quiere instrumentar el sistema de ventilación de un invernadero. Para ello se dispone de un sensor de temperatura digital **DS18B20**. El programa debe comunicarse a través del bus OneWire para obtener la temperatura en grados Celsius (Rango de trabajo de 0ºC a 50ºC).

Posteriormente, se debe cambiar la orientación de la **compuerta de ventilación** de forma proporcional: 0ºC implica compuerta cerrada (0º) y 50ºC implica compuerta totalmente abierta (90º).

Para lograr este movimiento, la compuerta tiene conectada un **motor paso a paso** de 200 pulsos por vuelta. Para verificar la posición, se dispone de un **encoder absoluto de 4 bits** con codificación Gray conectado al eje.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/823/temperatura` con el valor de temperatura actual en ºC.
* Topic: `sja003/invernadero/823/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[20, 22, 25, 24, 21]"`.

El número **823** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

---

## Problema 101
Se quiere instrumentar el sistema de ventilación de un invernadero. Para ello se dispone de un sensor de temperatura digital **DS18B20**. El programa debe comunicarse a través del bus OneWire para obtener la temperatura en grados Celsius (Rango de trabajo de 0ºC a 50ºC).

Posteriormente, se debe cambiar la orientación de la **compuerta de ventilación** de forma proporcional: 0ºC implica compuerta cerrada (0º) y 50ºC implica compuerta totalmente abierta (90º).

Para lograr este movimiento, la compuerta tiene conectada un **motor paso a paso** de 200 pulsos por vuelta. Para verificar la posición, se dispone de un **potenciómetro** conectado que mide la posición de la compuerta para asegurar que es correcta.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/829/temperatura` con el valor de temperatura actual en ºC.
* Topic: `sja003/invernadero/829/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[20, 22, 25, 24, 21]"`.

El número **829** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

---

## Problema 110
Se quiere instrumentar el sistema de ventilación de un invernadero. Para ello se dispone de un sensor de temperatura digital **DS18B20**. El programa debe comunicarse a través del bus OneWire para obtener la temperatura en grados Celsius (Rango de trabajo de 0ºC a 50ºC).

Posteriormente, se debe cambiar la orientación de la **compuerta de ventilación** de forma proporcional: 0ºC implica compuerta cerrada (0º) y 50ºC implica compuerta totalmente abierta (90º).

Para lograr este movimiento, la compuerta tiene conectada un **motor de continua** con su driver, controlado mediante señal PWM (velocidad proporcional a la tensión). Para verificar la posición, se dispone de un **encoder absoluto de 4 bits** con codificación Gray conectado al eje.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/950/temperatura` con el valor de temperatura actual en ºC.
* Topic: `sja003/invernadero/950/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[20, 22, 25, 24, 21]"`.

El número **950** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.

---

## Problema 111
Se quiere instrumentar el sistema de ventilación de un invernadero. Para ello se dispone de un sensor de temperatura digital **DS18B20**. El programa debe comunicarse a través del bus OneWire para obtener la temperatura en grados Celsius (Rango de trabajo de 0ºC a 50ºC).

Posteriormente, se debe cambiar la orientación de la **compuerta de ventilación** de forma proporcional: 0ºC implica compuerta cerrada (0º) y 50ºC implica compuerta totalmente abierta (90º).

Para lograr este movimiento, la compuerta tiene conectada un **motor de continua** con su driver, controlado mediante señal PWM (velocidad proporcional a la tensión). Para verificar la posición, se dispone de un **potenciómetro** conectado que mide la posición de la compuerta para asegurar que es correcta.

De forma adicional, el programa debe publicar en el servidor MQTT **broker.emqx.io**:
* Topic: `sja003/invernadero/988/temperatura` con el valor de temperatura actual en ºC.
* Topic: `sja003/invernadero/988/historico` con el array de las medias de las últimas 5 horas. Ejemplo: `"[20, 22, 25, 24, 21]"`.

El número **988** del topic es un ejemplo; debéis sustituirlo por vuestras 3 últimas cifras del DNI.
