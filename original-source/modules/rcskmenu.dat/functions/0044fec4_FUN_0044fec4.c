/*
 * FUN_0044fec4 at 0044fec4
 * undefined FUN_0044fec4(void)
 * Address ranges: 0044fec4-0044ff14
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044fec4(int param_1,undefined *param_2)

{
  LPCSTR lpFileName;
  LPCSTR lpAppName;
  BOOL BVar1;
  undefined4 uVar2;
  LPCSTR lpKeyName;
  LPCSTR lpString;
  undefined4 uStack_10;
  undefined1 uStack_c;
  
  lpFileName = FUN_00403f94(*(undefined **)(param_1 + 4));
  lpString = (LPCSTR)0x0;
  lpKeyName = (LPCSTR)0x0;
  lpAppName = FUN_00403f94(param_2);
  BVar1 = WritePrivateProfileStringA(lpAppName,lpKeyName,lpString,lpFileName);
  if (BVar1 == 0) {
    uStack_10 = *(undefined4 *)(param_1 + 4);
    uStack_c = 0xb;
    uVar2 = FUN_0040ad5c((int)&DAT_004070f4,'\x01',(undefined4 *)PTR_PTR_0047c8f8,0,&uStack_10);
    FUN_00403604(uVar2);
  }
  return;
}

