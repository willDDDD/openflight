# Final Project

This dataset provides us with the absolute location (latitude and
longitude) and airlines of every airport. We can use the absolute location to
calculate the distance between two airports. (https://openflights.org/data.html) The two
datasets we will use are airport dataset and route dataset. The format of the dataset
will be a .dat file where each line contains detailed information for an airline route.
## Name

OpenFlights data structure

## Visual
![graph](./project/output_image_test.png)


## Environment

Use clang++.

```bash
CXX = clang++
```
## Datasets

[OpenFilghts airlines.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airlines.dat)

[OpenFlights routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat)

## Data Structure

Adjacent List


Vertices: 
a unique id of the airport, latitude, longitude, and some pointers.
According to their latitude and longitude, putting them in the right place in the
graph.

Edges: 
two nodes are connected by an edge if there exist an airline between them
Graph drawing: using the number of incident edges connected to each node to
decide its color. The color varies according to the degree of the node.

## Usage

```python
import foobar

foobar.pluralize('word') # returns 'words'
foobar.pluralize('goose') # returns 'geese'
foobar.singularize('phenomena') # returns 'phenomenon'
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Authors and acknowledgment

Xinlong Dai

Xiuhao Ding

Zongxian Feng

Siyi Yu


## License
[MIT](https://choosealicense.com/licenses/mit/)