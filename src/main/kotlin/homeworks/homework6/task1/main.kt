package homeworks.homework6.task1

import kotlin.random.Random
import kotlinx.coroutines.launch
import kotlinx.coroutines.runBlocking
import kotlin.system.measureTimeMillis

fun <T> quickSort(array: Array<T>, indexBegin: Int, indexEnd: Int) where T : Comparable<T> {
    if (indexBegin < indexEnd) {
        val middle = array[(indexBegin + indexEnd) / 2]
        var i = indexBegin
        var j = indexEnd
        while (i <= j) {
            while (array[i] < middle) {
                i++
            }
            while (array[j] > middle) {
                j--
            }
            if (i >= j) {
                break
            }
            val temporary = array[i]
            array[i] = array[j]
            array[j] = temporary
            i++
            j--
        }
        quickSort(array, indexBegin, j)
        quickSort(array, j + 1, indexEnd)
    }
}

suspend fun <T> asyncQuickSort(array: Array<T>, indexBegin: Int, indexEnd: Int) where T : Comparable<T> {
    if (indexBegin < indexEnd) {
        val middle = array[(indexBegin + indexEnd) / 2]
        var i = indexBegin
        var j = indexEnd
        while (i <= j) {
            while (array[i] < middle) {
                i++
            }
            while (array[j] > middle) {
                j--
            }
            if (i >= j) {
                break
            }
            val temporary = array[i]
            array[i] = array[j]
            array[j] = temporary
            i++
            j--
        }
        asyncQuickSort(array, indexBegin, j)
        asyncQuickSort(array, j + 1, indexEnd)
    }
}

private const val SIZE_OF_ARRAY = 1_000_000
private const val MAX_NUMBER = 10_000

fun main() {
    val arrayToSort = Array(SIZE_OF_ARRAY) { Random.nextInt(-MAX_NUMBER, MAX_NUMBER) }

    val arrayForUsualQuickSort = arrayToSort.clone()
    val usualQuickSortTime = measureTimeMillis {
        quickSort(arrayForUsualQuickSort, 0, arrayForUsualQuickSort.lastIndex)
    }

    val arrayForAsyncQuickSort = arrayToSort.clone()
    val asyncQuickSortTime = measureTimeMillis {
        runBlocking {
            launch {
                asyncQuickSort(arrayForAsyncQuickSort, 0, arrayForAsyncQuickSort.lastIndex)
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
