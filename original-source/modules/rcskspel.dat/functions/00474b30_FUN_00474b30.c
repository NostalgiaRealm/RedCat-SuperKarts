/*
 * FUN_00474b30 at 00474b30
 * undefined FUN_00474b30(void)
 * Address ranges: 00474b30-00474c58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00474b79) */

undefined4 __thiscall FUN_00474b30(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 local_1c [4];
  int local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0988;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar3 = FUN_00431390(local_1c,param_1 + 0x18,param_2);
  uVar1 = *(uint *)(iVar3 + 8);
  local_4 = 0;
  if (param_3 == iVar3) {
    FUN_004478a0(uVar1,0xffffffff);
    FUN_004478a0(0,0);
  }
  else {
    if (uVar1 != 0) {
      puVar4 = *(undefined1 **)(iVar3 + 4);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = &DAT_004d2404;
      }
      if ((byte)puVar4[-1] < 0xfe) {
        FUN_0040b4f0(1);
        puVar4 = *(undefined1 **)(iVar3 + 4);
        if (puVar4 == (undefined1 *)0x0) {
          puVar4 = &DAT_004d2404;
        }
        *(undefined1 **)(param_3 + 4) = puVar4;
        *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
        puVar4[-1] = puVar4[-1] + '\x01';
        goto LAB_00474c18;
      }
    }
    cVar2 = FUN_0040b600(uVar1,1);
    if (cVar2 != '\0') {
      puVar6 = *(undefined4 **)(iVar3 + 4);
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)&DAT_004d2404;
      }
      puVar7 = *(undefined4 **)(param_3 + 4);
      for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar7 = (undefined4 *)((int)puVar7 + 1);
      }
      FUN_0040b5e0(uVar1);
    }
  }
LAB_00474c18:
  if (local_18 != 0) {
    cVar2 = *(char *)(local_18 + -1);
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_004bc150((char *)(local_18 + -1));
    }
    else {
      *(char *)(local_18 + -1) = cVar2 + -1;
    }
  }
  ExceptionList = local_c;
  return CONCAT31((int3)((uint)*(int *)(param_3 + 8) >> 8),*(int *)(param_3 + 8) != 0);
}

