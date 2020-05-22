package tests.test2

object FieldCreator {
    private fun createRandomListWithRepeatingElements(fieldSize: Int): List<Int> {
        val randomList = mutableListOf<Int>()
        for (i in 0 until ((fieldSize * fieldSize) / 2)) {
            randomList.add(i)
        }
        randomList.addAll(randomList)
        randomList.shuffle()
        return randomList
    }

    fun createField(fieldSize: Int): Array<IntArray> {
        val randomList = createRandomListWithRepeatingElements(fieldSize)
        val field = Array(fieldSize) { IntArray(fieldSize) }
        for (i in 0 until fieldSize) {
            for (j in 0 until fieldSize) {
                field[i][j] = randomList[i * fieldSize + j]
            }
        }

        return field
    }
}
