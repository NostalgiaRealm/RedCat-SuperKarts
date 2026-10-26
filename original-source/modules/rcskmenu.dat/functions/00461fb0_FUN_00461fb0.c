/*
 * FUN_00461fb0 at 00461fb0
 * undefined __register FUN_00461fb0(int param_1, undefined4 * param_2, byte param_3)
 * Address ranges: 00461fb0-004620a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00461fb0(int param_1,undefined4 *param_2,byte param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar7;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  uint *local_1c;
  uint *local_18;
  byte *local_14;
  undefined4 local_10;
  byte local_9;
  undefined4 *local_8;
  
  local_18 = (uint *)0x0;
  local_1c = (uint *)0x0;
  local_14 = (byte *)0x0;
  puStack_2c = (undefined1 *)0x461fd4;
  local_9 = param_3;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  puStack_30 = &LAB_004620a6;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  local_10 = 0;
  puStack_2c = &stack0xfffffffc;
  iVar2 = FUN_0044268c(param_1);
  if (0 < iVar2) {
    iVar2 = FUN_0044268c(param_1);
    if (-1 < iVar2 + -1) {
      iVar6 = 0;
      do {
        uVar7 = 1;
        FUN_00403e1c((int *)&local_14,local_8,*(undefined4 **)(PTR_PTR_0047c830 + (uint)local_9 * 4)
                    );
        iVar3 = FUN_00442650(param_1,iVar6);
        FUN_00407ca8(*(byte **)(iVar3 + 8),(int *)&local_18);
        puVar1 = local_18;
        FUN_00407ca8(local_14,(int *)&local_1c);
        FUN_00403ee0(puVar1,local_1c);
        if ((bool)uVar7) {
          piVar4 = (int *)FUN_00442650(param_1,iVar6);
          uVar5 = FUN_00403024(piVar4,(int)&PTR_FUN_0042022c);
          if ((char)uVar5 != '\0') {
            piVar4 = (int *)FUN_00442650(param_1,iVar6);
            local_10 = FUN_0040303c(piVar4,(int)&PTR_FUN_0042022c);
            break;
          }
        }
        iVar6 = iVar6 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  *in_FS_OFFSET = uStack_34;
  puStack_2c = &LAB_004620ad;
  puStack_30 = (undefined1 *)0x46209d;
  FUN_00403b74((int *)&local_1c,3);
  puStack_30 = (undefined1 *)0x4620a5;
  FUN_00403b50((int *)&local_8);
  return;
}

