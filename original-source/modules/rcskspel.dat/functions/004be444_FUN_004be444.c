/*
 * FUN_004be444 at 004be444
 * undefined FUN_004be444(void)
 * Address ranges: 004be444-004be555
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004be444(LPWSTR param_1,byte *param_2,uint param_3,byte *param_4,int *param_5)

{
  byte bVar1;
  UINT CodePage;
  int iVar2;
  
  if ((param_2 != (byte *)0x0) && (param_3 != 0)) {
    bVar1 = *param_2;
    if (bVar1 != 0) {
      CodePage = DAT_006b675c;
      iVar2 = DAT_006b674c;
      if (param_5 != (int *)0x0) {
        CodePage = param_5[1];
        iVar2 = *param_5;
      }
      if (iVar2 == 0) {
        if (param_1 != (LPWSTR)0x0) {
          *param_1 = (ushort)bVar1;
        }
        return 1;
      }
      if (*(int *)param_4 == 0) {
        if ((PTR_DAT_00502d80[(uint)bVar1 * 2 + 1] & 0x80) == 0) {
          iVar2 = MultiByteToWideChar(CodePage,9,(LPCSTR)param_2,1,param_1,
                                      (uint)(param_1 != (LPWSTR)0x0));
          if (iVar2 != 0) {
            return 1;
          }
        }
        else {
          if (param_3 < DAT_00502f8c) {
            *param_4 = bVar1;
            return 0xfffffffe;
          }
          if ((1 < (int)DAT_00502f8c) &&
             (iVar2 = MultiByteToWideChar(CodePage,9,(LPCSTR)param_2,DAT_00502f8c,param_1,
                                          (uint)(param_1 != (LPWSTR)0x0)), iVar2 != 0)) {
            return DAT_00502f8c;
          }
          if (param_2[1] != 0) {
            return DAT_00502f8c;
          }
          param_4[0] = 0;
          param_4[1] = 0;
          param_4[2] = 0;
          param_4[3] = 0;
        }
      }
      else {
        param_4[1] = bVar1;
        if ((1 < (int)DAT_00502f8c) &&
           (iVar2 = MultiByteToWideChar(CodePage,9,(LPCSTR)param_4,2,param_1,
                                        (uint)(param_1 != (LPWSTR)0x0)), iVar2 != 0)) {
          param_4[0] = 0;
          param_4[1] = 0;
          param_4[2] = 0;
          param_4[3] = 0;
          return DAT_00502f8c;
        }
        param_4[0] = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        param_4[3] = 0;
      }
      _DAT_006b66e8 = 0x2a;
      return 0xffffffff;
    }
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
  }
  return 0;
}

