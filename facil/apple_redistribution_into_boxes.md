# Redistribución de manzanas en cajas

Se te dan dos arreglos de enteros:

- **apple** de tamaño `n`, donde `apple[i]` representa el número de manzanas en el paquete `i`.
- **capacity** de tamaño `m`, donde `capacity[j]` representa la capacidad máxima (en manzanas) de la caja `j`.

## Objetivo

Determinar el **número mínimo de cajas** que debes seleccionar para poder **redistribuir todas las manzanas** de los paquetes en las cajas.

### Consideraciones importantes

- Las manzanas de **un mismo paquete pueden repartirse entre varias cajas**.
- Cada caja tiene un límite máximo de manzanas que puede contener.
- Solo importa que la **capacidad total de las cajas seleccionadas** sea **mayor o igual** al número total de manzanas.
- Se garantiza que siempre existe una solución válida.

---

## Ejemplos

### Ejemplo 1

**Entrada:**
```text
apple = [1, 3, 2]
capacity = [4, 3, 1, 5, 2]
