# Mailing Actividades Extracurriculares

Esta aplicación ha sido desarrollada en el curso de Ingeniería de Software para gestionar un sistema de mailing entre universidades, facilitando la organización y participación en actividades extracurriculares. Se ha implementado en C++, de manera que se muestre, gracias a un menú, por terminal el resultado.

## Miembros del equipo de trabajo 

- [Ángel Eduardo Bauste De Nicolais](https://github.com/Bania1)
- [Javier González Casares](https://github.com/i12gocaj)
- [Francisco Arroyo Alcaide](https://github.com/p02aralf)
- [Juan Higuera Mohedano](https://github.com/juannhm02)


## Datos a tener en cuenta en la ejecución de la aplicación:

Es importante asegurarse de que todos los ficheros de entrada estén correctamente formateados y contengan los datos necesarios para el funcionamiento de la aplicación. Esto incluye listas de actividades, usuarios y cualquier otro dato relevante.

## Compilación del proyecto

Para compilar el proyecto, utiliza el siguiente comando, asegurándote de incluir todos los archivos necesarios:

```c++
g++ -std=c++11 -o execute menu.cpp gestionarActividad.cpp Inscripcion.cpp ListaDifusion.cpp Certificado.cpp Usuario.cpp
```

## Ejecución

Para ejecutar la aplicación, ve a la carpeta donde se encuentra el ejecutable(execute), que en nuestro caso será la carpeta de /views y ejecuta el siguiente comando:

```c++
./execute
```

## Resultado final
La aplicación te presentará un menú interactivo en la terminal, donde podrás seleccionar entre diversas opciones para gestionar actividades, inscribirte en ellas, enviar y gestionar listas de difusión, y generar y enviar certificados, entre otras funciones.