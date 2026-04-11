NOMBRE DEL ESTUDIANTE: MIGUEL ANGEL SANDOVAL
NOMBRE DEL PROYECTO: Liga MG

Descripción
Este taller es una aplicación desarrollada en **C++** que permite gestionar una liga de fútbol desde consola.

El sistema permite:

* Registrar partidos
* Calcular automáticamente la tabla de posiciones
* Consultar jornadas
* Ver partidos registrados
* Consultar historial entre equipos
* Editar resultados de partidos
Además, exporta la tabla en formato **CSV**, compatible con Excel (funcion adicional).

Lenguaje utilizado
Lenguaje: **C++**
Librerías estándar:

  * `<iostream>`
  * `<fstream>`
  * `<sstream>`
  * `<string>`
  * `<vector>`
  * `<algorithm>`
  * `<cstdio>`

Estructura del proyecto

LIGA/
│
├── src/
│   - main.cpp
│
├── data/
│   - config.txt
│   - partidos.txt
│   - fechas.txt
│   - tabla.csv
│
└── README.md

 Archivos importantes

config.txt

Define el nombre de la liga y los equipos:

nombre=Liga mg
equipo=barcelona
equipo=realMadrid
equipo=atletico
equipo=sevilla
equipo=valencia
equipo=villarreal

 partidos.txt

Guarda los partidos en formato:

YYYY-MM-DD|equipoLocal|equipoVisitante|golesLocal|golesVisitante
Ejemplo:
2026-03-04|atletico|sevilla|1|2

 fechas.txt

Guarda las fechas (jornadas):
Ejemplo
2026-03-04
2026-03-05

 tabla.csv

Archivo generado automáticamente que puede abrirse en Excel.

 Cómo ejecutar el programa

1 Compilar

Ubícate en la carpeta `src`:
cd src
g++ main.cpp -o liga

Ejecutar

Desde la carpeta principal:

.\src\liga

Funcionalidades

1. Ver tabla

* Calcula estadísticas automáticamente
* Ordena por:

  * Puntos
  * Diferencia de gol
  * Goles a favor
* Exporta a `tabla.csv`

 2. Registrar partido

* Valida que los equipos existan
* Evita equipos iguales
* Evita partidos duplicados en la misma fecha

3. Ver jornadas

* Muestra todas las fechas registradas

 4. Ver partidos

* Lista todos los partidos guardados

 5. Historial entre equipos

* Muestra todos los enfrentamientos entre dos equipos

 6. Editar partido

* Permite modificar resultados existentes
* Reescribe completamente el archivo `partidos.txt`

 Funcionalidades adicionales implementadas

- Desempate múltiple (PTS → DG → GF)
- Detección de partidos duplicados
- Exportación a CSV (Excel)
- Historial entre equipos
- Edición de resultados

 Restricciones cumplidas

- No uso de `map`, `set`, `list`
- No uso de bases de datos
- No uso de librerías externas
- Sin herencia (POO)
- Uso de estructuras basicas

Importante
* El programa es ejecutado completamente en consola
* Los datos se almacenan en archivos de texto
* El archivo CSV puede abrirse en Excel para mejor visualización
