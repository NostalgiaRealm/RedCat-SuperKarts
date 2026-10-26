/*
 * FUN_00413fec at 00413fec
 * undefined __register FUN_00413fec(int param_1, int * param_2, uint param_3)
 * Address ranges: 00413fec-00414027
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00413fec(int param_1,int *param_2,uint param_3)

{
  undefined4 *puVar1;
  uint local_c;
  
  local_c = param_3;
  FUN_0041292c(param_1,&local_c,1);
  FUN_00403c38(param_2,(undefined4 *)0x0,local_c & 0xff);
  puVar1 = (undefined4 *)FUN_00403fa0(param_2);
  FUN_0041292c(param_1,puVar1,local_c & 0xff);
  return;
}

