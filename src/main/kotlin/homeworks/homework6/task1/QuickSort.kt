package homeworks.homework6.task1

class QuickSort {
    fun <T> simpleQuickSort(array: Array<T>, indexBegin: Int, indexEnd: Int) where T : Comparable<T> {
        if (indexBegin < indexEnd) {
            val j = partition(array, indexBegin, indexEnd)
            simpleQuickSort(array, indexBegin, j)
            simpleQuickSort(array, j + 1, indexEnd)
        }
    }

    suspend fun <T> asyncQuickSort(array: Array<T>, indexBegin: Int, indexEnd: Int) where T : Comparable<T> {
        if (indexBegin < indexEnd) {
            val j = partition(array, indexBegin, indexEnd)
            asyncQuickSort(array, indexBegin, j)
            asyncQuickSort(array, j + 1, indexEnd)
        }
    }

    private fun <T> partition(array: Array<T>, indexBegin: Int, indexEnd: Int): Int where T : Comparable<T> {
        var i = indexBegin
        var j = indexEnd
        val middle = array[(indexBegin + indexEnd) / 2]
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
            array[i] = array[j].also { array[j] = array[i] }
            i++
            j--
        }
        return j
    }
}
