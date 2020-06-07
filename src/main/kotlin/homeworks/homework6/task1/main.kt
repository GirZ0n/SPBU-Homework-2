package homeworks.homework6.task1

import kotlin.random.Random
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import kotlin.system.measureTimeMillis

fun generateArray(sizeOfArray: Int = 1000, maxNumber: Int = 10000) =
    Array(sizeOfArray) { Random.nextInt(-maxNumber, maxNumber) }

fun main() {
    val arrayToSort = generateArray()
    val quickSort = QuickSort()

    val arrayForUsualQuickSort = arrayToSort.clone()
    val usualQuickSortTime = measureTimeMillis {
        quickSort.simpleQuickSort(arrayForUsualQuickSort, 0, arrayForUsualQuickSort.lastIndex)
    }

    val arrayForAsyncQuickSort = arrayToSort.clone()
    val asyncQuickSortTime = measureTimeMillis {
        runBlocking {
            launch {
                quickSort.asyncQuickSort(arrayForAsyncQuickSort, 0, arrayForAsyncQuickSort.lastIndex)
            }
        }
    }

    val arrayForBuiltInSort = arrayToSort.clone()
    val builtInSortTime = measureTimeMillis {
        arrayForBuiltInSort.sortedArray()
    }

    println("Usual quicksort time: $usualQuickSortTime")
    println("Async quicksort time: $asyncQuickSortTime")
    println("Built-in sort time: $builtInSortTime")
}
