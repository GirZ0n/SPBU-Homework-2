package homeworks.homework1.task5

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*
import java.io.File
import java.io.FileNotFoundException

internal class Task5Test {

    @Test
    fun CountNonEmptyLines_FileDoesNotExist_MustWork() {
        val input = File("")
        assertThrows(FileNotFoundException::class.java) {
            assertEquals(0, countNonEmptyLines(input))
        }
    }

    @Test
    fun CountNonEmptyLines_EmptyFile_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/Empty.txt")
        assertEquals(0, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_BlankFile_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/Blank.txt")
        assertEquals(0, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_OneLineFile_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/OneLine.txt")
        assertEquals(1, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_OneLineWithLineFeedSymbolFile_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/OneLineWithLineFeed.txt")
        assertEquals(1, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile1_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/NonEmpty1.txt")
        assertEquals(12, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile2_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/NonEmpty2.txt")
        assertEquals(9, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile3_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/NonEmpty3.txt")
        assertEquals(8, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile4_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/NonEmpty4.txt")
        assertEquals(65, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile5_MustWork() {
        val input = File("./src/test/kotlin/homeworks/homework1/task5/testFiles/NonEmpty5.txt")
        assertEquals(30, countNonEmptyLines(input))
    }
}