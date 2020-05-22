package tests.test2

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class FieldCreatorTest {
    val fieldCreator = FieldCreator

    @Test
    fun createField_size2_MustWork() {
        val field = fieldCreator.createField(2)
        assert(checkField(2, field))
    }

    @Test
    fun createField_size4_MustWork() {
        val field = fieldCreator.createField(4)
        assert(checkField(4, field))
    }

    @Test
    fun createField_size6_MustWork() {
        val field = fieldCreator.createField(6)
        assert(checkField(6, field))
    }

    @Test
    fun createField_size8_MustWork() {
        val field = fieldCreator.createField(6)
        assert(checkField(6, field))
    }

    @Test
    fun createField_size10_MustWork() {
        val field = fieldCreator.createField(6)
        assert(checkField(6, field))
    }
}

private fun checkField(fieldSize: Int, field: Array<IntArray>): Boolean {
    val count = IntArray((fieldSize * fieldSize) / 2) { 0 }
    for (i in 0 until fieldSize) {
        for (j in 0 until fieldSize) {
            count[field[i][j]]++
        }
    }

    for (elem in count) {
        if (elem != 2) {
            return false
        }
    }
    return true
}
