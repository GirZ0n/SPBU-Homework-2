import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*
import java.io.File

internal class Task5Test {

    @Test
    fun CountNonEmptyLines_EmptyFile_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/Empty.txt")
        assertEquals(0, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_BlankFile_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/Blank.txt")
        assertEquals(0, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_OneLineFile_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/OneLine.txt")
        assertEquals(1, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_OneLineWithLineFeedSymbolFile_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/OneLineWithLineFeed.txt")
        assertEquals(1, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile1_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/NonEmpty1.txt")
        assertEquals(12, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile2_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/NonEmpty2.txt")
        assertEquals(9, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile3_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/NonEmpty3.txt")
        assertEquals(8, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile4_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/NonEmpty4.txt")
        assertEquals(65, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile5_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/NonEmpty5.txt")
        assertEquals(30, countNonEmptyLines(input))
    }

    @Test
    fun CountNonEmptyLines_NonEmptyFile6_MustWork() {
        val input = File("./src/test/kotlin/TestFiles/NonEmpty6.txt")
        assertEquals(9, countNonEmptyLines(input))
    }
}