
        patterns:
 
         pointers::p_DamageSpoof1 = MemoryManager::FindSignatureStr(xorstr_("F3 0F 59 B8 ? ? ? ? EB ? 45 84 ED"), 0, 0);
         pointers::p_DamageSpoof2 = MemoryManager::FindSignatureStr(xorstr_("F3 0F 10 80 ? ? ? ? E9 ? ? ? ? 41 BC"), 0, 0);
 
 
 
 
        void DamageBoost(bool enable, float value)
       {
          if (enable == DamagePatch)
              return;
 
          DamagePatch = enable;
 
          MemoryManager::Write(MemoryManager::ModBase + 0x400, enable ? value : 0.f);
          MemoryManager::Write(pointers::p_DamageSpoof1, enable ? 0xFEFA98AF3D590FF3 : 0x00000D5CB8590FF3);
          MemoryManager::Write(pointers::p_DamageSpoof2, enable ? 0xFFBF5B7505100FF3 : 0x00000D5C80100FF3);
      }
