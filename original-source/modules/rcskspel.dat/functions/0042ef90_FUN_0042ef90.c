/*
 * FUN_0042ef90 at 0042ef90
 * undefined FUN_0042ef90(void)
 * Address ranges: 0042ef90-0042f065
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

byte FUN_0042ef90(int param_1,int param_2,int *param_3,int *param_4)

{
  byte bVar1;
  int local_c;
  int local_8;
  uint local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  if (DAT_0053a5e8 == 0) {
    FUN_004afee0(s__handle_input_module__input_modu_004eacc8);
  }
  if (DAT_0053a5d8 != 3) {
    FUN_004afee0(s__handle_input_module__trying_to_r_004ead10);
  }
  FUN_004bac90(1,param_1,param_2,&local_c,&local_8,&local_4);
  if (param_1 < local_c) {
    local_c = param_1;
  }
  if (local_c < 0) {
    local_c = 0;
  }
  if (param_2 < local_8) {
    local_8 = param_2;
  }
  if (local_8 < 0) {
    local_8 = 0;
  }
  *param_3 = local_c;
  *param_4 = local_8;
  bVar1 = (local_4 & 4) != 0;
  if ((local_4 & 8) != 0) {
    bVar1 = bVar1 | 2;
  }
  if ((local_4 & 1) != 0) {
    bVar1 = bVar1 | 4;
  }
  if ((local_4 & 2) != 0) {
    bVar1 = bVar1 | 8;
  }
  if ((local_4 & 0x10) != 0) {
    bVar1 = bVar1 | 0x10;
  }
  if ((local_4 & 0x20) != 0) {
    bVar1 = bVar1 | 0x20;
  }
  if ((local_4 & 0x40) != 0) {
    bVar1 = bVar1 | 0x40;
  }
  if ((local_4 & 0x80) != 0) {
    bVar1 = bVar1 | 0x80;
  }
  return bVar1;
}

