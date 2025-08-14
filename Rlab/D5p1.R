pearson = function(x, y, z) {
  n = length(x)
  
  mean_x = mean(x)
  mean_y = mean(y)
  mean_z = mean(z)
  
  sd_x = sqrt(sum((x - mean_x)^2) / n)
  sd_y = sqrt(sum((y - mean_y)^2) / n)
  sd_z = sqrt(sum((z - mean_z)^2) / n)
  
  num = sum(x * y * z) - n * mean_x * mean_y * mean_z
  den = n * sd_x * sd_y * sd_z
  
  r = num / den
  return(r)
}
