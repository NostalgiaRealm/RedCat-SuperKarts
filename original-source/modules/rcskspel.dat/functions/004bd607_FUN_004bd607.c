/*
 * FUN_004bd607 at 004bd607
 * undefined FUN_004bd607(void)
 * Address ranges: 004bd607-004bd68e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004bd607(int *param_1,undefined2 *param_2,undefined4 *param_3)

{
  undefined2 *puVar1;
  short sVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  int local_8;
  
  local_8 = 0;
  while( true ) {
    while( true ) {
      if ((int)param_3 < 1) {
        return local_8;
      }
      puVar3 = (undefined4 *)param_1[8];
      puVar5 = (undefined2 *)*puVar3;
      if ((puVar5 == (undefined2 *)0x0) ||
         (puVar3 = (undefined4 *)((*(int *)param_1[0xc] << 1) >> 1), (int)puVar3 < 1)) break;
      puVar1 = param_2;
      puVar4 = puVar3;
      if ((int)param_3 < (int)puVar3) {
        puVar3 = param_3;
        puVar4 = param_3;
      }
      for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)((int)puVar3 + -1)) {
        *puVar5 = *puVar1;
        puVar5 = puVar5 + 1;
        puVar1 = puVar1 + 1;
      }
      local_8 = local_8 + (int)puVar4;
      param_3 = (undefined4 *)((int)param_3 - (int)puVar4);
      param_2 = param_2 + (int)puVar4;
      FUN_004bdcdd(puVar4);
    }
    sVar2 = (**(code **)(*param_1 + 4))(CONCAT22((short)((uint)puVar3 >> 0x10),*param_2));
    if (sVar2 == -1) break;
    param_2 = param_2 + 1;
    local_8 = local_8 + 1;
    param_3 = (undefined4 *)((int)param_3 + -1);
  }
  return local_8;
}

