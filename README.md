# Mailing Actividades Extracurriculares

Esta aplicación ha sido desarrollada en el curso de Ingeniería de Software para gestionar un sistema de mailing entre universidades, facilitando la organización y participación en actividades extracurriculares. Se ha implementado en C++, de manera que se muestre, gracias a un menú, por terminal el resultado.

## Miembros del equipo de trabajo 

- [Ángel Eduardo Bauste De Nicolais](https://github.com/Bania1)
- [Javier González Casares](https://github.com/i12gocaj)
- [Francisco Arroyo Alcaide](https://github.com/p02aralf)
- [Juan Higuera Mohedano](https://github.com/juannhm02)

## Ficheros de Datos
En estos ficheros se almacenan los datos relevantes para el funcionamiento del sistema. Algunos de estos ficheros pueden ser binarios y no legibles directamente con un editor de texto.

- archivoUsuarios.txt: Contiene información sobre los usuarios registrados en el sistema.
- actividadesEnCurso.txt: Almacena datos de las actividades que están actualmente en curso.
- actividadesFinalizadas.txt: Registra las actividades que han sido finalizadas.
- actividadesNoIniciadas.txt: Incluye las actividades que están planificadas pero aún no han iniciado.
- inscripciones.txt: Guarda la información sobre las inscripciones a las diferentes actividades.

### Modelos
Las siguientes entidades se han incluido en el proyecto:

- Actividad: Representa una actividad extracurricular, con atributos como ID, nombre, descripción, estado (no iniciada, en curso, finalizada), entre otros.
- Usuario: Contiene la información de los usuarios, como ID, nombre, correo electrónico, y posiblemente otros atributos relacionados con su participación en las actividades.
- Inscripción y certificados: Serán gestionadas todas desde el modelo de Actividad.

### Gestores

- GestorActividades: Encargado de la administración de actividades. Se ocupa de la creación, modificación y consulta de las actividades extracurriculares.
- GestorUsuarios: Responsable de la gestión de los usuarios, incluyendo su registro, actualización de datos y consulta.
- GestorVariablesGlobales: Administra las variables globales que van a ser utilizadas a lo largo de nuestro proyecto.

Esta es la base de nuestro proyecto, a medida que vayamos usando las funcionalidades que se expresan, se generarán diferentes directorios para almacenar dicha información, por ejemplo las referidas a certificados, inscripciones o listas de difusion.

## Datos a tener en cuenta en la ejecución de la aplicación:

Es importante asegurarse de que todos los ficheros de entrada estén correctamente formateados y contengan los datos necesarios para el funcionamiento de la aplicación. Esto incluye listas de actividades, usuarios y cualquier otro dato relevante.

Es crucial que tengamos en cuenta los espacios o los saltos de línea que puedan generarse en los ficheros de los que está formado el sistema. 

## Compilación del proyecto

Para compilar el proyecto, utiliza el siguiente comando, asegurándote de incluir todos los archivos necesarios:

```c++
make
```

## Ejecución

Para ejecutar la aplicación, desde el directorio /src, es decir en el que nos encontramos, tendremos que ejecutar el siguiente comando para ver el funcionamiento de la misma:

```c++
./aplicacion
```
Para ejecutar los tests que comprueban el funcionamiento de nuestro sistema, deberemos de seguir los siguientes pasos:

```c++

make test 
```
De esta forma podremos ver todo el procedimiento donde van ejecutándose cada uno de estos, entendiendo que previamente se habrá hecho un make clean de los archivos ya existentes. 

De lo contrario, si lo que queremos es ver que finalmente han pasado todos los test con éxito, realizaremos el mismo procedimiento que para ejecutar nuestra aplicación, pero cambiando el ejecutable por test, de la forma:

```c++
./tests
```

## Resultado final
La aplicación presenta un menú interactivo en la terminal, donde se podrá seleccionar entre diversas opciones para gestionar actividades, inscribirte en ellas, enviar y gestionar listas de difusión, y generar y enviar certificados, entre otras funciones. Además, proporciona una comprobación exhaustiva de varias funciones con la realización de 8 test perfectamente identificados y definidos.
