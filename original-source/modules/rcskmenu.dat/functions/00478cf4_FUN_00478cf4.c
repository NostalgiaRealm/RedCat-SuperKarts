/*
 * FUN_00478cf4 at 00478cf4
 * undefined __register FUN_00478cf4(int param_1, byte param_2, undefined1 param_3)
 * Address ranges: 00478cf4-00478dc8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00478cf4(int param_1,byte param_2,undefined1 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar7;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  int local_10;
  uint *local_c;
  uint uStack_8;
  
  puStack_20 = &stack0xfffffffc;
  local_c = (uint *)0x0;
  local_10 = 0;
  uStack_8 = (uint)CONCAT11(param_2,param_3) << 0x10;
  puStack_24 = &LAB_00478dc9;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  FUN_00407f60((uint)param_2,&local_10);
  uVar1 = *(undefined4 *)(PTR_PTR_0047c7dc + (uStack_8 >> 0x10 & 0xff) * 4);
  FUN_00403e90((int *)&local_c,3);
  iVar2 = FUN_0044268c(param_1);
  if ((0 < iVar2) && (iVar2 = FUN_0044268c(param_1), -1 < iVar2 + -1)) {
    iVar6 = 0;
    uVar7 = true;
    do {
      iVar3 = FUN_00442650(param_1,iVar6);
      FUN_00403ee0(*(uint **)(iVar3 + 8),local_c);
      if ((bool)uVar7) {
        piVar4 = (int *)FUN_00442650(param_1,iVar6);
        uVar5 = FUN_00403024(piVar4,(int)&PTR_FUN_004536f0);
        if ((char)uVar5 != '\0') {
          piVar4 = (int *)FUN_00442650(param_1,iVar6);
          FUN_0040303c(piVar4,(int)&PTR_FUN_004536f0);
          break;
        }
      }
      iVar6 = iVar6 + 1;
      iVar2 = iVar2 + -1;
      uVar7 = iVar2 == 0;
    } while (!(bool)uVar7);
  }
  *in_FS_OFFSET = uVar1;
  FUN_00403b74(&local_10,2);
  return;
}

