/*
 * FUN_00417448 at 00417448
 * undefined __register FUN_00417448(HANDLE param_1, undefined4 * param_2)
 * Address ranges: 00417448-004174f9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00417448(HANDLE param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_6c [4];
  int local_5c;
  char local_58;
  char local_57;
  char local_56;
  undefined1 local_55;
  byte local_51;
  char local_50 [32];
  byte local_30 [36];
  
  puVar2 = &DAT_0047b374;
  puVar3 = param_2;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (param_1 != (HANDLE)0x0) {
    iVar1 = GetObjectA(param_1,0x3c,local_6c);
    if (iVar1 != 0) {
      param_2[1] = local_6c[0];
      if (699 < local_5c) {
        *(byte *)((int)param_2 + 9) = *(byte *)((int)param_2 + 9) | 1;
      }
      if (local_58 == '\x01') {
        *(byte *)((int)param_2 + 9) = *(byte *)((int)param_2 + 9) | 2;
      }
      if (local_57 == '\x01') {
        *(byte *)((int)param_2 + 9) = *(byte *)((int)param_2 + 9) | 4;
      }
      if (local_56 == '\x01') {
        *(byte *)((int)param_2 + 9) = *(byte *)((int)param_2 + 9) | 8;
      }
      *(undefined1 *)((int)param_2 + 10) = local_55;
      FUN_00402c70((char *)local_30,local_50,0x20);
      FUN_00402a30((byte *)((int)param_2 + 0xb),local_30,0x1f);
      if ((local_51 & 0xf) == 1) {
        *(undefined1 *)(param_2 + 2) = 2;
      }
      else if ((local_51 & 0xf) == 2) {
        *(undefined1 *)(param_2 + 2) = 1;
      }
      else {
        *(undefined1 *)(param_2 + 2) = 0;
      }
      *param_2 = param_1;
    }
  }
  return;
}

