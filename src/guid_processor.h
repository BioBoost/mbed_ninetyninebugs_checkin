#pragma once

namespace NinetyNineBugsCheckin {

  class GuidProcessor {
    public:
      virtual uint32_t process_guid(uint32_t guidStringPointer) = 0;
  };

};
