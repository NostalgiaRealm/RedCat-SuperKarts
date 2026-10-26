/*
 * FUN_00418a68 at 00418a68
 * undefined __register FUN_00418a68(int * param_1, byte param_2)
 * Address ranges: 00418a68-00418ad7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418a68(int *param_1,byte param_2)

{
  int *piVar1;
  byte bVar2;
  
  bVar2 = ~*(byte *)(param_1 + 2) & param_2;
  if (bVar2 != 0) {
    if ((bVar2 & 1) != 0) {
      (**(code **)(*param_1 + 0x14))();
      if (param_1[1] == 0) {
        piVar1 = FUN_0040ad20((int *)&DAT_0040de0c,'\x01',(undefined4 *)PTR_PTR_0047c750);
        FUN_00403604(piVar1);
      }
    }
    if ((bVar2 & 2) != 0) {
      FUN_00418b04((int)param_1);
    }
    if ((bVar2 & 4) != 0) {
      FUN_00418b30((int)param_1);
    }
    if ((bVar2 & 8) != 0) {
      FUN_00418b60((int)param_1);
    }
    *(byte *)(param_1 + 2) = bVar2 | *(byte *)(param_1 + 2);
  }
  return;
}

