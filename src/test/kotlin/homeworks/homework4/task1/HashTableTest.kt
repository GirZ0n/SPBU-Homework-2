package homeworks.homework4.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

internal class HashTableTest {
    private val simpleHashFunction = SimpleHashFunctionForString()
    private val polynomialHashFunction = PolynomialHashFunctionForString()

    @Test
    fun numberOfEntries_EmptyHashTable_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        assertEquals(0, hashTable.numberOfEntries)
    }

    @Test
    fun numberOfEntries_NonEmptyHashTable_AddAndRemoveElements_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.remove("q")
        hashTable.add("d,gnoi3nt34", 0)
        hashTable.remove("")
        assertEquals(4, hashTable.numberOfEntries)
    }

    @Test
    fun find_emptyHashTable_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        assertNull(hashTable.find("124f"))
    }

    @Test
    fun find_nullKey_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        assertNull(hashTable.find(null))
    }

    @Test
    fun find_keyIsInHashTable_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        assertEquals(6124, hashTable.find("q"))
    }

    @Test
    fun find_keyIsNotInHashTable_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        assertNull(hashTable.find(""))
    }

    @Test
    fun changeHashFunction_fromPolynomialToSimple_Find_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        hashTable.changeHashFunction(simpleHashFunction)
        assertEquals(6124, hashTable.find("q"))
    }

    @Test
    fun changeHashFunction_fromPolynomialToSimple_NumberOfEntries_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        hashTable.changeHashFunction(simpleHashFunction)
        assertEquals(5, hashTable.numberOfEntries)
    }

    @Test
    fun changeHashFunction_fromSimpleToPolynomial_Find_MustWork() {
        val hashTable = HashTable<String, Int>(simpleHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        hashTable.changeHashFunction(polynomialHashFunction)
        assertEquals(6124, hashTable.find("q"))
    }

    @Test
    fun changeHashFunction_fromSimpleToPolynomial_NumberOfEntries_MustWork() {
        val hashTable = HashTable<String, Int>(simpleHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        hashTable.changeHashFunction(polynomialHashFunction)
        assertEquals(5, hashTable.numberOfEntries)
    }

    @Test
    fun addAndRemove_OneElement_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        hashTable.add("qwerty", 38258)
        hashTable.remove("qwerty")
        assertEquals(0, hashTable.numberOfEntries)
    }

    @Test
    fun addAndRemove_ManyElements_MustWork() {
        val hashTable = HashTable<String, Int>(polynomialHashFunction)
        for (i in 0..1000) {
            hashTable.add("$i", i)
        }

        for (i in 0..1000) {
            hashTable.remove("$i")
        }
        assertEquals(0, hashTable.numberOfEntries)
    }
}
