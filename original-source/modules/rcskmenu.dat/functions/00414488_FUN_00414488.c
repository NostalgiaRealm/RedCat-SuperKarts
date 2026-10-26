/*
 * FUN_00414488 at 00414488
 * undefined FUN_00414488(void)
 * Address ranges: 00414488-0041452c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414488(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uVar2;
  char *pcStack_14;
  undefined1 uStack_10;
  char *pcStack_c;
  int iStack_8;
  
  pcStack_c = (char *)0x0;
  uVar2 = *in_FS_OFFSET;
  *in_FS_OFFSET = &stack0xffffffd4;
  FUN_00403be8((int *)&pcStack_c,param_2);
  iStack_8 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    iStack_8 = FUN_00414c8c(*(int *)(param_1 + 0x1c),pcStack_c);
  }
  if (iStack_8 == 0) {
    if (*(short *)(param_1 + 0x52) != 0) {
      (**(code **)(param_1 + 0x50))
                (*(undefined4 *)(param_1 + 0x54),param_1,pcStack_c,&iStack_8,param_3);
    }
    if (iStack_8 == 0) {
      pcStack_14 = pcStack_c;
      uStack_10 = 0xb;
      uVar2 = 0;
      uVar1 = FUN_0040ad5c((int)&DAT_0040dadc,'\x01',(undefined4 *)PTR_PTR_0047c714,0,&pcStack_14);
      FUN_00403604(uVar1);
    }
  }
  *in_FS_OFFSET = uVar2;
  FUN_00403b50((int *)&pcStack_c);
  return;
}

