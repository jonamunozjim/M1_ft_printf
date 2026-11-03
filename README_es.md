*Este proyecto ha sido creado como parte del currículo de 42 por jmunoz-j.*

<div align="right">
  <strong>Languages:</strong>
  <a href="README.md">English</a> ｜ 
  <a href="README_es.md">Español</a>
</div>

# ft_printf

## Descripción
El objetivo de este proyecto es reimplementar la función `printf()` de la biblioteca estándar de C (libc). 

Al reescribir esta función, adquieres un profundo conocimiento de las funciones variádicas en C (usando un número variable de argumentos). La clave para un `ft_printf` exitoso es escribir un código bien estructurado y extensible. A diferencia del `printf()` original, esta implementación personalizada no gestiona el búfer. El resultado es una biblioteca estática (`libftprintf.a`) que puede usarse como una herramienta fundamental en futuros proyectos de 42.

## Instrucciones

### Requisitos previos
Para compilar este proyecto necesitarás:
- Un compilador de C (como `gcc` o `clang`).
- La utilidad `make`.

### Compilación
1. Clona este repositorio en tu máquina local.
2. Navega hasta la raíz del repositorio.
3. Ejecuta el comando `make` en tu terminal.

Esto compilará los archivos fuente con las flags `-Wall`, `-Wextra` y `-Werror`, creando la biblioteca estática `libftprintf.a`.

**Comandos de Makefile disponibles:**
- `make` / `make all`: Compila la biblioteca estática `libftprintf.a`.
- `make clean`: Elimina los archivos objeto (`.o`) generados durante la compilación.
- `make fclean`: Ejecuta `clean` y también elimina el archivo de la biblioteca compilada (`libftprintf.a`).

## Conversiones soportadas

| Especificador | Descripción |
|---|---|
| `%c` | Imprime un solo carácter. |
| `%s` | Imprime una string (tal como se define en la convención común de C). |
| `%p` | El argumento del puntero `void *` se imprime en formato hexadecimal. |
| `%d` | Imprime un número decimal (base 10). |
| `%i` | Imprime un entero en base 10. |
| `%u` | Imprime un número decimal sin signo (base 10). |
| `%x` | Imprime un número en formato hexadecimal (base 16) en minúsculas. |
| `%X` | Imprime un número en formato hexadecimal (base 16) en mayúsculas. |
| `%%` | Imprime un signo de porcentaje literal. |

## Algoritmo y estructura de datos
**Algoritmo:**
El algoritmo principal es un analizador sintáctico (parser) de strings de una sola pasada. Itera a través de la string de formato carácter por carácter usando un bucle `while`.
- Cuando se encuentra un carácter estándar, se imprime directamente en la salida estándar usando la función `write`.
- Cuando se encuentra el símbolo `%`, actúa como un disparador. El algoritmo avanza al siguiente carácter y usa un mecanismo de selección (una serie de sentencias `if / else if`) para determinar el especificador de formato solicitado.
- Basado en el especificador, el algoritmo extrae la variable correspondiente usando `va_arg` y la dirige a funciones auxiliares específicas (`ft_putstr`, `ft_putnbr_hex`, etc.) para darle formato e imprimirla.
- El número total de caracteres impresos se acumula continuamente. Si alguna operación `write` falla, la función captura el error (`if (n < 0)`) y devuelve inmediatamente `-1`, coincidiendo con el comportamiento del `printf` original.

**Estructura de datos:**
Para gestionar el número variable de argumentos, el proyecto se basa exclusivamente en la estructura `va_list` proporcionada por la biblioteca `<stdarg.h>` (`va_start`, `va_arg`, `va_copy`, `va_end`). No se utilizaron estructuras de datos de almacenamiento intermedio interno (como arrays o strings dinámicas), adhiriéndose estrictamente a la restricción del proyecto de no gestionar el búfer del `printf` original.

# Recursos
## Documentación y referencias
- Páginas del manual del sistema operativo: `man 3 printf`, `man 3 stdarg`.
- Reglas oficiales del compilador GCC y especificaciones de la Norma de 42 (Norminette).

# Uso de Inteligencia Artificial
Durante el desarrollo de este proyecto, la IA se utilizó como una herramienta de apoyo educativo para:
- Traducir e interpretar registros de errores de herramientas como Valgrind.
- Entender la estricta lógica de extracción de argumentos de `va_arg`.

Se instruyó explícitamente a la IA para que no proporcionara código resuelto, sino que se limitara a explicar la lógica subyacente y señalar fallos algorítmicos, asegurando que todo el código del proyecto fuera escrito e iterado de forma autónoma.