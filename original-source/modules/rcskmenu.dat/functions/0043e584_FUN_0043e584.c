/*
 * FUN_0043e584 at 0043e584
 * undefined FUN_0043e584(void)
 * Address ranges: 0043e584-0043e64a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043e584(int param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  undefined4 *in_FS_OFFSET;
  undefined4 **ppuVar3;
  undefined4 uStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  int iStack_20;
  int iStack_1c;
  undefined1 uStack_18;
  int iStack_14;
  undefined1 uStack_10;
  undefined4 *puStack_c;
  undefined1 uStack_5;
  
  puStack_30 = &stack0xfffffffc;
  puStack_c = (undefined4 *)0x0;
  iStack_20 = 0;
  puStack_34 = &LAB_0043e64b;
  uStack_38 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_38;
  uStack_5 = 1;
  uVar2 = FUN_00403024(*(int **)(param_1 + 0x10),(int)&PTR_FUN_0042618c);
  if ((char)uVar2 != '\0') {
    cVar1 = FUN_00403088(*(int **)(param_1 + 0x10),param_2,extraout_ECX);
    if ((((cVar1 != '\0') && (*(char *)(*(int *)PTR_DAT_0047c86c + 0x6c) != '\0')) &&
        (*(short *)(*(int *)(param_1 + 0x10) + 0x68) != 0)) && (*param_2 != 0)) {
      ppuVar3 = &puStack_c;
      iStack_1c = *param_2;
      uStack_18 = 0xb;
      FUN_00435978(*(ushort *)(*(int *)(param_1 + 0x10) + 0x68),&iStack_20);
      iStack_14 = iStack_20;
      uStack_10 = 0xb;
      FUN_00408a5c((byte *)"%s (%s)",&iStack_1c,1,(int *)ppuVar3);
      FUN_00403ba4(param_2,puStack_c);
    }
  }
  *in_FS_OFFSET = uStack_38;
  puStack_30 = &LAB_0043e652;
  puStack_34 = (undefined1 *)0x43e642;
  FUN_00403b50(&iStack_20);
  puStack_34 = (undefined1 *)0x43e64a;
  FUN_00403b50((int *)&puStack_c);
  return;
}

