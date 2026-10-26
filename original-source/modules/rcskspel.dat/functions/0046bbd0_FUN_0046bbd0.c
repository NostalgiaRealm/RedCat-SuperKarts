/*
 * FUN_0046bbd0 at 0046bbd0
 * undefined FUN_0046bbd0(void)
 * Address ranges: 0046bbd0-0046bd0d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0046bc10) */

undefined1 * __thiscall
FUN_0046bbd0(undefined1 *param_1,undefined1 param_2,undefined4 *param_3,uint param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uVar1 = param_4;
  puVar6 = param_3;
  puStack_8 = &LAB_004d0278;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = param_2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  local_4 = 0;
  if (param_1 == &param_2) {
    FUN_004478a0(param_4,0xffffffff);
    FUN_004478a0(0,0);
    puVar6 = param_3;
  }
  else {
    if (param_4 != 0) {
      puVar3 = (undefined4 *)&DAT_004d2404;
      if (param_3 != (undefined4 *)0x0) {
        puVar3 = param_3;
      }
      if (*(byte *)((int)puVar3 + -1) < 0xfe) {
        FUN_0040b4f0(1);
        puVar3 = (undefined4 *)&DAT_004d2404;
        if (puVar6 != (undefined4 *)0x0) {
          puVar3 = puVar6;
        }
        *(undefined4 **)(param_1 + 4) = puVar3;
        *(uint *)(param_1 + 8) = param_4;
        *(undefined4 *)(param_1 + 0xc) = param_5;
        *(char *)((int)puVar3 + -1) = *(char *)((int)puVar3 + -1) + '\x01';
        goto LAB_0046bcbd;
      }
    }
    cVar2 = FUN_0040b600(param_4,1);
    if (cVar2 != '\0') {
      if (puVar6 == (undefined4 *)0x0) {
        puVar6 = (undefined4 *)&DAT_004d2404;
      }
      puVar3 = *(undefined4 **)(param_1 + 4);
      for (uVar5 = uVar1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar3 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar3 = puVar3 + 1;
      }
      for (uVar5 = uVar1 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined1 *)puVar3 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      FUN_0040b5e0(uVar1);
      puVar6 = param_3;
    }
  }
LAB_0046bcbd:
  *(undefined4 *)(param_1 + 0x10) = param_6;
  *(undefined4 *)(param_1 + 0x14) = param_7;
  uVar4 = __ftol();
  *(undefined4 *)(param_1 + 0x18) = uVar4;
  if (puVar6 != (undefined4 *)0x0) {
    cVar2 = *(char *)((int)puVar6 + -1);
    if ((cVar2 == '\0') || (cVar2 == -1)) {
      FUN_004bc150((undefined1 *)((int)puVar6 + -1));
    }
    else {
      *(char *)((int)puVar6 + -1) = cVar2 + -1;
    }
  }
  ExceptionList = local_c;
  return param_1;
}

