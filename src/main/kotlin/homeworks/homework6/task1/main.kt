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

/*
SIZE_OF_ARRAY = 100_000_000
MAX_NUMBER = 10_000

Attempt: 1
Usual quicksort time: 95217
Async quicksort time: 101058

Attempt: 2
Usual quicksort time: 66394
Async quicksort time: 69378

Attempt: 3
Usual quicksort time: 72054
Async quicksort time: 71507

Attempt: 4
Usual quicksort time: 69329
Async quicksort time: 66916
Built-in sort time: 55989

Attempt: 5
Usual quicksort time: 66897
Async quicksort time: 69979
Built-in sort time: 47790

Attempt: 6
Usual quicksort time: 65295
Async quicksort time: 67682
Built-in sort time: 57695

-------------------------------
SIZE_OF_ARRAY = 1_000_000
MAX_NUMBER = 10_000

Async quicksort time < usual quicksort time: 52 / 1000
*/
