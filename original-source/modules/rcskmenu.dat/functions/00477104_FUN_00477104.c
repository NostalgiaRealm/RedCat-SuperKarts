/*
 * FUN_00477104 at 00477104
 * undefined __register FUN_00477104(int param_1, undefined4 * param_2, undefined4 param_3)
 * Address ranges: 00477104-004771c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00477104(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar6;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  undefined4 *local_10;
  uint *local_c;
  undefined4 *local_8;
  
  local_c = (uint *)0x0;
  local_10 = (undefined4 *)0x0;
  puStack_20 = (undefined1 *)0x47711f;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_24 = &LAB_004771c8;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  puStack_20 = &stack0xfffffffc;
  FUN_00407f60(param_3,(int *)&local_10);
  FUN_00403e1c((int *)&local_c,local_8,local_10);
  iVar1 = FUN_0044268c(param_1);
  if ((0 < iVar1) && (iVar1 = FUN_0044268c(param_1), -1 < iVar1 + -1)) {
    iVar5 = 0;
    uVar6 = true;
    do {
      iVar2 = FUN_00442650(param_1,iVar5);
      FUN_00403ee0(*(uint **)(iVar2 + 8),local_c);
      if ((bool)uVar6) {
        piVar3 = (int *)FUN_00442650(param_1,iVar5);
        uVar4 = FUN_00403024(piVar3,(int)&PTR_FUN_0042022c);
        if ((char)uVar4 != '\0') {
          piVar3 = (int *)FUN_00442650(param_1,iVar5);
          FUN_0040303c(piVar3,(int)&PTR_FUN_0042022c);
          break;
        }
      }
      iVar5 = iVar5 + 1;
      iVar1 = iVar1 + -1;
      uVar6 = iVar1 == 0;
    } while (!(bool)uVar6);
  }
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_004771cf;
  puStack_24 = (undefined1 *)0x4771c7;
  FUN_00403b74((int *)&local_10,3);
  return;
}

