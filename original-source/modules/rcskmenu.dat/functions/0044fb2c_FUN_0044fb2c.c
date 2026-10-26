/*
 * FUN_0044fb2c at 0044fb2c
 * undefined FUN_0044fb2c(void)
 * Address ranges: 0044fb2c-0044fb95
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044fb2c(int param_1,undefined *param_2,undefined *param_3,undefined *param_4)

{
  LPCSTR lpFileName;
  LPCSTR lpString;
  LPCSTR lpKeyName;
  LPCSTR lpAppName;
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined1 uStack_8;
  
  lpFileName = FUN_00403f94(*(undefined **)(param_1 + 4));
  lpString = FUN_00403f94(param_4);
  lpKeyName = FUN_00403f94(param_3);
  lpAppName = FUN_00403f94(param_2);
  BVar1 = WritePrivateProfileStringA(lpAppName,lpKeyName,lpString,lpFileName);
  if (BVar1 == 0) {
    uStack_c = *(undefined4 *)(param_1 + 4);
    uStack_8 = 0xb;
    uVar2 = FUN_0040ad5c((int)&DAT_004070f4,'\x01',(undefined4 *)PTR_PTR_0047c8f8,0,&uStack_c);
    FUN_00403604(uVar2);
  }
  return;
}

