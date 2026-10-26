/*
 * FUN_0048e840 at 0048e840
 * undefined FUN_0048e840(void)
 * Address ranges: 0048e840-0048e96f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048e840(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 fVar6;
  undefined4 local_40 [16];
  
  piVar2 = (int *)FUN_0048e740(param_1);
  if ((piVar2 != (int *)0x0) && (*(char *)((int)piVar2 + 0x11) != '\0')) {
    if (piVar2[2] < 0x11) {
      FUN_004afce0(s_HandleSquashedObject___UNsquashi_004fa248);
      iVar1 = *(int *)(*piVar2 * 0xd0 + 0xc + DAT_0067ee20);
      if (*(char *)((int)piVar2 + 0x12) == '\0') {
        FUN_004a09e0();
      }
      iVar1 = iVar1 * 0xa9;
      puVar4 = (undefined4 *)(iVar1 + 0x10 + DAT_006a5c38);
      puVar5 = local_40;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_004a17c0(local_40,&DAT_0067e4e0 + piVar2[2] * 0x40,local_40);
      puVar4 = local_40;
      puVar5 = (undefined4 *)(iVar1 + 0x10 + DAT_006a5c38);
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      fVar6 = (float10)FUN_0048f4e0();
      if ((float10)10.0 <= (float10)1.0 / (fVar6 + (float10)0.01)) {
        piVar2[2] = piVar2[2] + 1;
        FUN_004afce0(s_HandleSquashedObject___UNsquashi_004fa26c);
        return;
      }
    }
    piVar2[2] = 0;
    *(undefined1 *)((int)piVar2 + 0x11) = 0;
    *(undefined1 *)(piVar2 + 4) = 0;
    FUN_004afce0(s_HandleSquashedObject___UNsquashi_004fa26c);
  }
  return;
}

