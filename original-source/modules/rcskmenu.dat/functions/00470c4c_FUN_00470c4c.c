/*
 * FUN_00470c4c at 00470c4c
 * undefined FUN_00470c4c(void)
 * Address ranges: 00470c4c-00470cea
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00470c4c(undefined4 param_1,int param_2,int *param_3)

{
  int *in_FS_OFFSET;
  undefined4 **ppuVar1;
  char *pcVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iStack_34;
  undefined *puStack_30;
  undefined1 *puStack_2c;
  int iStack_28;
  undefined *puStack_24;
  undefined1 *puStack_20;
  undefined4 *puStack_18;
  undefined4 *puStack_14;
  int *piStack_10;
  int *piStack_c;
  int iStack_8;
  
  puStack_18 = (undefined4 *)0x0;
  puStack_14 = (undefined4 *)0x0;
  puStack_20 = (undefined1 *)0x470c69;
  piStack_c = param_3;
  iStack_8 = param_2;
  FUN_00403f84(param_2);
  puStack_24 = &UNK_00470d15;
  iStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_28;
  puStack_30 = &UNK_00470ceb;
  iStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&iStack_34;
  uVar4 = *(undefined4 *)PTR_DAT_0047c694;
  puVar3 = &UNK_00470d2c;
  pcVar2 = "settings.ini";
  puStack_2c = &stack0xfffffffc;
  puStack_20 = &stack0xfffffffc;
  FUN_00403e90((int *)&puStack_18,3);
  piStack_10 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',puStack_18);
  ppuVar1 = &puStack_14;
  (**(code **)*piStack_10)(piStack_10,"WINMOVIES",iStack_8,ppuVar1,0,pcVar2,puVar3,uVar4);
  *in_FS_OFFSET = (int)ppuVar1;
  FUN_00402eac(piStack_10);
  FUN_00403ba4(piStack_c,puStack_14);
  return;
}

