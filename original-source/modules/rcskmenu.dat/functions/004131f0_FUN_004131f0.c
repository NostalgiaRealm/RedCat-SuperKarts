/*
 * FUN_004131f0 at 004131f0
 * undefined __register FUN_004131f0(int param_1, int * param_2, uint param_3)
 * Address ranges: 004131f0-00413216;0041323d-004132b0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004131f0(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint local_c;
  
  local_c = param_3;
  uVar1 = FUN_004140d0(param_1,param_2,param_3);
  switch(uVar1 & 0x7f) {
  case 0:
    FUN_00403ba4(param_2,(undefined4 *)&DAT_004132e8);
    break;
  default:
    FUN_004124c0();
    break;
  case 7:
    FUN_0041292c(param_1,&local_c,1);
    FUN_00403c38(param_2,(undefined4 *)0x0,local_c & 0xff);
    puVar2 = (undefined4 *)FUN_00403fa0(param_2);
    FUN_0041292c(param_1,puVar2,local_c & 0xff);
    break;
  case 8:
    FUN_00403ba4(param_2,(undefined4 *)"False");
    break;
  case 9:
    FUN_00403ba4(param_2,(undefined4 *)&DAT_004132cc);
    break;
  case 0xd:
    FUN_00403ba4(param_2,(undefined4 *)&DAT_004132dc);
  }
  return;
}

