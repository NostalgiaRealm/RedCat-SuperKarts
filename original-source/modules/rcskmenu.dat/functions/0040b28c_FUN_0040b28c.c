/*
 * FUN_0040b28c at 0040b28c
 * undefined FUN_0040b28c(void)
 * Address ranges: 0040b28c-0040b346
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040b28c(int *param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffd4;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  byte *pbStack_14;
  int iStack_10;
  undefined1 uStack_c;
  int *piStack_8;
  
  puStack_1c = &stack0xfffffffc;
  pbStack_14 = (byte *)0x0;
  puStack_20 = &LAB_0040b347;
  puStack_24 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_24;
  piStack_8 = param_1;
  uVar1 = FUN_0040b02c(param_1);
  uVar1 = uVar1 & 0xff;
  if (7 < uVar1 - 3) {
    if (uVar1 == 0xb) {
      in_stack_ffffffd4 = 0x40b2e5;
      piVar2 = (int *)FUN_0040b0c0();
      goto LAB_0040b31a;
    }
    if (9 < uVar1 - 0xc) {
      iStack_10 = *piStack_8;
      uStack_c = 0;
      piVar2 = &iStack_10;
      in_stack_ffffffd4 = 0;
      FUN_00405438((undefined4 *)PTR_PTR_0047c5fc,(int *)&pbStack_14);
      piVar2 = (int *)FUN_0040aca0((int)&DAT_00407318,'\x01',pbStack_14,in_stack_ffffffd4,piVar2);
      goto LAB_0040b31a;
    }
  }
  piVar2 = FUN_0040ac64(*(int **)(&DAT_0047b22c + uVar1 * 8),'\x01',
                        *(undefined4 **)(&DAT_0047b230 + uVar1 * 8));
LAB_0040b31a:
  uVar3 = FUN_00403024(piVar2,(int)&DAT_004072c0);
  if ((char)uVar3 != '\0') {
    piVar2[3] = (int)piStack_8;
  }
  *in_FS_OFFSET = in_stack_ffffffd4;
  puStack_24 = &LAB_0040b34e;
  FUN_00403b50((int *)&pbStack_14);
  return;
}

