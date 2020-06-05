package homeworks.homework4.task1

import org.junit.jupiter.api.Test

import org.junit.jupiter.api.Assertions.*

const val INIT_SIZE = 1024

internal class HashTableTest {
    private val simpleHashFunction = SimpleHashFunctionForString()
    private val polynomialHashFunction = PolynomialHashFunctionForString()

    @Test
    fun numberOfEntries_EmptyHashTable_MustWork() {
        val hashTable = HashTable<String, Int>(INIT_SIZE, polynomialHashFunction)
        assertEquals(0, hashTable.numberOfEntries)
    }

    @Test
    fun numberOfEntries_NonEmptyHashTable_AddAndRemoveElements_MustWork() {
        val hashTable = HashTable<String, Int>(INIT_SIZE, polynomialHashFunction)
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
        val hashTable = HashTable<String, Int>(INIT_SIZE, polynomialHashFunction)
        assertNull(hashTable.find("124f"))
    }

    @Test
    fun find_nullKey_MustWork() {
        val hashTable = HashTable<String, Int>(INIT_SIZE, polynomialHashFunction)
        assertNull(hashTable.find(null))
    }

    @Test
    fun find_keyIsInHashTable_MustWork() {
        val hashTable = HashTable<String, Int>(INIT_SIZE, polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        assertEquals(6124, hashTable.find("q"))
    }

    @Test
    fun find_keyIsNotInHashTable_MustWork() {
        val hashTable = HashTable<String, Int>(INIT_SIZE, polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        assertNull(hashTable.find(""))
    }

    @Test
    fun changeHashFunction_fromPolynomialToSimple_MustWork() {
        val hashTable = HashTable<String, Int>(INIT_SIZE, polynomialHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        hashTable.changeHashFunction(simpleHashFunction)
        assertEquals(6124, hashTable.find("q"))
    }

    @Test
    fun changeHashFunction_fromSimpleToPolynomial_MustWork() {
        val hashTable = HashTable<String, Int>(INIT_SIZE, simpleHashFunction)
        hashTable.add("qwerty", 6)
        hashTable.add("q", 6124)
        hashTable.add("4kegnu934h", 32523)
        hashTable.add("5451916", 2)
        hashTable.add("d,gnoi3nt34", 0)
        hashTable.changeHashFunction(polynomialHashFunction)
        assertEquals(6124, hashTable.find("q"))
    }
}
