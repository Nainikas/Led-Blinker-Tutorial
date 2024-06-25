// ======================================================================
// \title  Led.hpp
// \author nainika
// \brief  hpp file for Led component implementation class
// ======================================================================

#ifndef Components_Led_HPP
#define Components_Led_HPP

#include "Components/Led/LedComponentAc.hpp"
#include <Os/Mutex.hpp>
#include <Fw/Types/OnEnumAc.hpp>

namespace Components {

  class Led :
    public LedComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct Led object
      Led(
          const char* const compName //!< The component name
      );

      //! Destroy Led object
      ~Led();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      //!
      void run_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Emit parameter updated EVR
      //!
      void parameterUpdated(FwPrmIdType id /*!< The parameter ID*/
      );
      //! Implementation for BLINKING_ON_OFF command handler
      //! Command to turn on or off the blinking LED
      void BLINKING_ON_OFF_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          Fw::On on_off /*!< 
          Indicates whether the blinking should be on or off
          */
      );
    Os::Mutex lock; //! Protects our data from thread race conditions
    Fw::On state; //! Keeps track if LED is on or off
    U64 transitions; //! The number of on/off transitions that have occurred from FSW boot up
    U32 count; //! Keeps track of how many ticks the LED has been on for
    bool blinking; //! Flag: if true then LED blinking will occur else
  };

}

#endif
