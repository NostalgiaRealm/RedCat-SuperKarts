/*
 * FUN_00415370 at 00415370
 * undefined FUN_00415370(void)
 * Address ranges: 00415370-00415401
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415370(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined1 local_c [12];
  
  fVar4 = (float10)FUN_00414ff0(param_1,0,param_2);
  puVar3 = (undefined4 *)FUN_00415160(local_18,param_1,(float)fVar4,0,param_2);
  uVar1 = *puVar3;
  uVar2 = puVar3[1];
  local_10 = puVar3[2];
  fVar4 = (float10)FUN_00414ff0(param_1,2,param_2);
  puVar3 = (undefined4 *)FUN_00415160(local_c,param_1,(float)fVar4,2,param_2);
  FUN_00415280(param_1,uVar1,uVar2,local_10,*puVar3,puVar3[1],puVar3[2]);
  return;
}

