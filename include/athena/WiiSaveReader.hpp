#pragma once

#include "athena/Global.hpp"
#include "athena/MemoryReader.hpp"

namespace athena {
class WiiSave;
class WiiBanner;
class WiiFile;
class WiiImage;

namespace io {

/*! \class WiiSaveReader
 *  \brief Wii data.bin reader class
 *
 *  A Class for reading binary data from a wii data.bin file,
 *  all work is done using a memory buffer, and not read directly from the disk.
 *  \sa BinaryReader
 */
class WiiSaveReader : public MemoryCopyReader {
public:
  /*! \brief This constructor takes an existing buffer to read from.
   *
   *   \param data The existing buffer
   *   \param length The length of the existing buffer
   */
  WiiSaveReader(const atUint8*, atUint64);

  /*! \brief This constructor creates an instance from a file on disk.
   *
   * \param filename The file to create the stream from
   */
  WiiSaveReader(const std::string&);

  /*!
   * \brief readSave
   * \return
   */
  std::unique_ptr<WiiSave> readSave();

private:
  WiiBanner* readBanner();
  WiiFile* readFile();
  WiiImage* readImage(atUint32 width, atUint32 height);
  void readCerts(atUint32 totalSize);
  WiiFile* buildTree(std::vector<WiiFile*> files);
};

} // namespace io
} // namespace athena
