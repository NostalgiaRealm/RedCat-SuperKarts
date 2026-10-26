/*
 * FUN_0040b600 at 0040b600
 * undefined FUN_0040b600(void)
 * Address ranges: 0040b600-0040b719
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0040b600(int param_1,uint param_2,char param_3)

{
  char cVar1;
  undefined1 *puVar2;
  
  if (0xfffffffd < param_2) {
    FUN_004bc15b();
  }
  puVar2 = *(undefined1 **)(param_1 + 4);
  if (((puVar2 == (undefined1 *)0x0) || (cVar1 = puVar2[-1], cVar1 == '\0')) || (cVar1 == -1)) {
    if (param_2 == 0) {
      if (param_3 == '\0') {
        if (puVar2 != (undefined1 *)0x0) {
          *(undefined4 *)(param_1 + 8) = 0;
          *puVar2 = 0;
        }
        return 0;
      }
      if (puVar2 != (undefined1 *)0x0) {
        cVar1 = puVar2[-1];
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          puVar2[-1] = cVar1 + -1;
          *(undefined4 *)(param_1 + 4) = 0;
          *(undefined4 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0xc) = 0;
          return 0;
        }
        FUN_004bc150(puVar2 + -1);
      }
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      return 0;
    }
    if (param_3 != '\0') {
      if ((*(uint *)(param_1 + 0xc) < 0x20) && (param_2 <= *(uint *)(param_1 + 0xc))) {
        return 1;
      }
      if (puVar2 != (undefined1 *)0x0) {
        cVar1 = puVar2[-1];
        if ((cVar1 != '\0') && (cVar1 != -1)) {
          puVar2[-1] = cVar1 + -1;
          *(undefined4 *)(param_1 + 4) = 0;
          *(undefined4 *)(param_1 + 8) = 0;
          *(undefined4 *)(param_1 + 0xc) = 0;
          FUN_0040b720(param_2);
          return 1;
        }
        FUN_004bc150(puVar2 + -1);
      }
      *(undefined4 *)(param_1 + 4) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      FUN_0040b720(param_2);
      return 1;
    }
    if (param_2 <= *(uint *)(param_1 + 0xc)) {
      return 1;
    }
  }
  else if (param_2 == 0) {
    puVar2[-1] = cVar1 + -1;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return 0;
  }
  FUN_0040b720(param_2);
  return 1;
}

