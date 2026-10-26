/*
 * FUN_004c9be4 at 004c9be4
 * undefined FUN_004c9be4(void)
 * Address ranges: 004c9be4-004c9e41
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004c9be4(void)

{
  char cVar1;
  char cVar2;
  char *_Str1;
  DWORD DVar3;
  int iVar4;
  size_t sVar5;
  char *_Source;
  int local_4;
  
  DAT_006b6910 = 0;
  DAT_00503758 = 0xffffffff;
  DAT_00503748 = 0xffffffff;
  _Str1 = (char *)FUN_004c0c21(&DAT_004d4054);
  if (_Str1 == (char *)0x0) {
    DVar3 = GetTimeZoneInformation((LPTIME_ZONE_INFORMATION)&DAT_006b6918);
    if (DVar3 == 0xffffffff) {
      return;
    }
    DAT_005036b0 = DAT_006b6918 * 0x3c;
    DAT_006b6910 = 1;
    if (DAT_006b695e != 0) {
      DAT_005036b0 = DAT_005036b0 + DAT_006b696c * 0x3c;
    }
    if ((DAT_006b69b2 == 0) || (DAT_006b69c0 == 0)) {
      DAT_005036b4 = 0;
      DAT_005036b8 = 0;
    }
    else {
      DAT_005036b4 = 1;
      DAT_005036b8 = (DAT_006b69c0 - DAT_006b696c) * 0x3c;
    }
    iVar4 = WideCharToMultiByte(DAT_006b675c,0x220,(LPCWSTR)&DAT_006b691c,-1,PTR_DAT_0050373c,0x3f,
                                (LPCSTR)0x0,&local_4);
    if ((iVar4 == 0) || (local_4 != 0)) {
      *PTR_DAT_0050373c = 0;
    }
    else {
      PTR_DAT_0050373c[0x3f] = 0;
    }
    iVar4 = WideCharToMultiByte(DAT_006b675c,0x220,(LPCWSTR)&DAT_006b6970,-1,PTR_DAT_00503740,0x3f,
                                (LPCSTR)0x0,&local_4);
    if ((iVar4 != 0) && (local_4 == 0)) {
      PTR_DAT_00503740[0x3f] = 0;
      return;
    }
  }
  else {
    if (*_Str1 == '\0') {
      return;
    }
    if ((DAT_006b69c4 != (char *)0x0) && (iVar4 = _strcmp(_Str1,DAT_006b69c4), iVar4 == 0)) {
      return;
    }
    FUN_004bff99(DAT_006b69c4);
    sVar5 = _strlen(_Str1);
    DAT_006b69c4 = _malloc(sVar5 + 1);
    if (DAT_006b69c4 == (char *)0x0) {
      return;
    }
    FUN_004c51f0(DAT_006b69c4,_Str1);
    _strncpy(PTR_DAT_0050373c,_Str1,3);
    _Source = _Str1 + 3;
    PTR_DAT_0050373c[3] = 0;
    cVar1 = *_Source;
    if (cVar1 == '-') {
      _Source = _Str1 + 4;
    }
    iVar4 = FUN_004bf787(_Source);
    DAT_005036b0 = iVar4 * 0xe10;
    for (; (cVar2 = *_Source, cVar2 == '+' || (('/' < cVar2 && (cVar2 < ':'))));
        _Source = _Source + 1) {
    }
    if (*_Source == ':') {
      _Source = _Source + 1;
      iVar4 = FUN_004bf787(_Source);
      DAT_005036b0 = DAT_005036b0 + iVar4 * 0x3c;
      for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
      }
      if (*_Source == ':') {
        _Source = _Source + 1;
        iVar4 = FUN_004bf787(_Source);
        DAT_005036b0 = DAT_005036b0 + iVar4;
        for (; ('/' < *_Source && (*_Source < ':')); _Source = _Source + 1) {
        }
      }
    }
    if (cVar1 == '-') {
      DAT_005036b0 = -DAT_005036b0;
    }
    DAT_005036b4 = (int)*_Source;
    if (DAT_005036b4 != 0) {
      _strncpy(PTR_DAT_00503740,_Source,3);
      PTR_DAT_00503740[3] = 0;
      return;
    }
  }
  *PTR_DAT_00503740 = 0;
  return;
}

