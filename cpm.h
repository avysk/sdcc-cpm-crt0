/** \file cpm.h
 *  \brief CP/M BDOS interface.
 *
 *  This module provides functions for interacting with CP/M BDOS (Basic
 *  Disk Operating System) for file I/O and console operations.
 */
#pragma once

#include <stdint.h>

/** \brief Open a file.
 *
 *  \param [in] file_number The file number (0 or 1 for command line files).
 *  \return 0 on success, 0xFF on failure.
 */
uint8_t f_open(uint8_t file_number);

/** \brief Close a file.
 *
 *  \param [in] file_number The file number (0 or 1 for command line files).
 *  \return 0 on success, 0xFF on failure.
 */
uint8_t f_close(uint8_t file_number);

/** \brief Delete a file.
 *
 *  Not harmful to delete a non-existing file.
 *
 *  \param [in] file_number The file number (0 or 1 for command line files).
 *  \return 0 on success, 0xFF on failure.
 */
uint8_t f_delete(uint8_t file_number);

/** \brief Create a new file.
 *
 *  \param [in] file_number The file number (0 or 1 for command line files).
 *  \return 0 on success, 0xFF on failure.
 */
uint8_t f_make(uint8_t file_number);

/** \brief Read a 128-byte record from a file.
 *
 *  CP/M reads/writes 128-byte records.
 *
 *  \param [in] file_number The file number (0 or 1 for command line files).
 *  \return Pointer to 128-byte DMA buffer, 0 for EOF, 0xFFFF on error.
 */
char (*f_read(uint8_t file_number))[128];

/** \brief Write a 128-byte record to a file.
 *
 *  CP/M reads/writes 128-byte records.
 *  Always make sure that the file exists before writing to it!
 *  Always close the file after writing is done!
 *
 *  \param [in] file_number The file number (0 or 1 for command line files).
 *  \param [in] record Pointer to 128 bytes of data to write.
 *  \return 0 OK, 1 directory full, 2 disk full, other value some CP/M error.
 */
uint8_t f_write(uint8_t file_number, const char record[static 128]);

/** \brief Read a line from console input.
 *
 *  \param [out] s Buffer to store the line.
 *  \param [in] size Size of the buffer.
 *  \return Pointer to buffer on success, NULL on EOF.
 */
char *gets(char *s, uint16_t size);
