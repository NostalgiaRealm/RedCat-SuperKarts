/*
 * FUN_0044fc98 at 0044fc98
 * undefined FUN_0044fc98(void)
 * Address ranges: 0044fc98-0044fd58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044fc98(int param_1,undefined *param_2,int *param_3)

{
  LPCSTR lpFileName;
  LPCSTR lpAppName;
  int iVar1;
  char *pcVar2;
  undefined4 *in_FS_OFFSET;
  LPCSTR lpKeyName;
  LPCSTR lpDefault;
  DWORD DVar3;
  undefined4 uStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  int iStack_10;
  char *pcStack_c;
  int *piStack_8;
  
  puStack_1c = &stack0xfffffffc;
  iStack_10 = 0;
  puStack_20 = &LAB_0044fd93;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_28 = (undefined1 *)0x44fcc4;
  piStack_8 = param_3;
  pcStack_c = (char *)FUN_00402714(0x4000);
  puStack_2c = &LAB_0044fd76;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  puStack_34 = (undefined1 *)0x44fcdd;
  puStack_28 = &stack0xfffffffc;
  FUN_0041073c(piStack_8);
  puStack_38 = &LAB_0044fd59;
  uStack_3c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_3c;
  puStack_34 = &stack0xfffffffc;
  (**(code **)(*piStack_8 + 0x40))();
  lpFileName = FUN_00403f94(*(undefined **)(param_1 + 4));
  DVar3 = 0x4000;
  lpDefault = (LPCSTR)0x0;
  lpKeyName = (LPCSTR)0x0;
  pcVar2 = pcStack_c;
  lpAppName = FUN_00403f94(param_2);
  DVar3 = GetPrivateProfileStringA(lpAppName,lpKeyName,lpDefault,pcVar2,DVar3,lpFileName);
  pcVar2 = pcStack_c;
  if (DVar3 != 0) {
    for (; *pcVar2 != '\0'; pcVar2 = pcVar2 + iVar1 + 1) {
      FUN_00403d08(&iStack_10,pcVar2);
      (**(code **)(*piStack_8 + 0x34))(piStack_8,iStack_10);
      iVar1 = FUN_00408340(pcVar2);
    }
  }
  *in_FS_OFFSET = uStack_3c;
  puStack_34 = &LAB_0044fd60;
  puStack_38 = (undefined1 *)0x44fd58;
  FUN_004107f8(piStack_8);
  return;
}

