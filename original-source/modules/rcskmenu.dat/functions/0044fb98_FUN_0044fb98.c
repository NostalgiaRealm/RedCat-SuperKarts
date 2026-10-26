/*
 * FUN_0044fb98 at 0044fb98
 * undefined FUN_0044fb98(void)
 * Address ranges: 0044fb98-0044fc4f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044fb98(int param_1,int *param_2)

{
  LPCSTR lpFileName;
  DWORD DVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  undefined1 *puStack_24;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  int iStack_10;
  LPSTR pCStack_c;
  int *piStack_8;
  
  puStack_18 = &stack0xfffffffc;
  iStack_10 = 0;
  puStack_1c = &LAB_0044fc8a;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  puStack_24 = (undefined1 *)0x44fbc1;
  piStack_8 = param_2;
  pCStack_c = (LPSTR)FUN_00402714(0x4000);
  puStack_28 = &LAB_0044fc6d;
  uStack_2c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_2c;
  puStack_30 = (undefined1 *)0x44fbda;
  puStack_24 = &stack0xfffffffc;
  FUN_0041073c(piStack_8);
  puStack_34 = &LAB_0044fc50;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  puStack_30 = &stack0xfffffffc;
  (**(code **)(*piStack_8 + 0x40))();
  lpFileName = FUN_00403f94(*(undefined **)(param_1 + 4));
  DVar1 = GetPrivateProfileStringA((LPCSTR)0x0,(LPCSTR)0x0,(LPCSTR)0x0,pCStack_c,0x4000,lpFileName);
  pcVar3 = pCStack_c;
  if (DVar1 != 0) {
    for (; *pcVar3 != '\0'; pcVar3 = pcVar3 + iVar2 + 1) {
      FUN_00403d08(&iStack_10,pcVar3);
      (**(code **)(*piStack_8 + 0x34))(piStack_8,iStack_10);
      iVar2 = FUN_00408340(pcVar3);
    }
  }
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_0044fc57;
  puStack_34 = (undefined1 *)0x44fc4f;
  FUN_004107f8(piStack_8);
  return;
}

