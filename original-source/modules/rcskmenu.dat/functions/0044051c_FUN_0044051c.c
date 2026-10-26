/*
 * FUN_0044051c at 0044051c
 * undefined __register FUN_0044051c(int * param_1, int * param_2, int * param_3)
 * Address ranges: 0044051c-004405ee
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044051c(int *param_1,int *param_2,int *param_3)

{
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_1c = *(int *)(param_1[0x19] + 0x14);
  if (local_1c == 0) {
    local_1c = 0;
  }
  local_18 = *(int *)(param_1[0x19] + 0x10);
  if (local_18 == 0) {
    local_18 = 0;
  }
  local_14 = *(int *)(param_1[0x19] + 0xc);
  if (local_14 == 0) {
    local_14 = 0;
  }
  local_10 = *(int *)(param_1[0x19] + 8);
  if (local_10 == 0) {
    local_10 = 0;
  }
  (**(code **)(*param_1 + 0x38))(param_1,&local_1c,&local_18);
  if ((local_1c < 1) || (*param_2 <= local_1c)) {
    if ((0 < (int)&local_10) && (*param_2 < (int)&local_10)) {
      *param_2 = (int)&local_10;
    }
  }
  else {
    *param_2 = local_1c;
  }
  if ((local_18 < 1) || (*param_3 <= local_18)) {
    if ((0 < (int)&local_14) && (*param_3 < (int)&local_14)) {
      *param_3 = (int)&local_14;
    }
  }
  else {
    *param_3 = local_18;
  }
  return;
}

